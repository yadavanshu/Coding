WITH latest_timestamps AS (
    SELECT
        resource_id,
        MAX(timestamp_utc_s) AS max_ts
    FROM
        cloud_azure_virtual_machines
    WHERE
        timestamp_utc_s > EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP AT TIME ZONE ${${sys.timezone}})) 
        AND timestamp_utc_s < EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP AT TIME ZONE ${${sys.timezone}}))
    GROUP BY
        resource_id
),
filtered_terminated_resources AS (
    SELECT
        resource_id
    FROM
        latest_timestamps
    WHERE
        max_ts < EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP AT TIME ZONE ${${sys.timezone}})) - 3600
)
SELECT 
    op1.existing AS "existing", 
    op2.running AS "running", 
    op3.unavailable AS "inactive",
    op4.terminated AS "terminated"
FROM 
    (
    SELECT 
        COUNT(DISTINCT resource_id) AS existing
    FROM 
        cloud_azure_virtual_machines cavm 
    WHERE 
        timestamp_utc_s > EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP AT TIME ZONE ${${sys.timezone}})) 
        AND timestamp_utc_s < EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP AT TIME ZONE ${${sys.timezone}}))
        AND resource_id NOT IN (SELECT resource_id FROM filtered_terminated_resources)
    ) AS op1,
    (
    SELECT 
        COUNT(DISTINCT resource_id) AS running
    FROM 
        cloud_azure_virtual_machines cavm 
    WHERE 
        state = 'active' 
        AND timestamp_utc_s > EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP AT TIME ZONE ${${sys.timezone}})) 
        AND timestamp_utc_s < EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP AT TIME ZONE ${${sys.timezone}}))
        AND resource_id NOT IN (SELECT resource_id FROM filtered_terminated_resources)
    ) AS op2,
    (
    SELECT 
        COUNT(DISTINCT resource_id) AS unavailable
    FROM 
        cloud_azure_virtual_machines cavm 
    WHERE 
        state = 'inactive' 
        AND timestamp_utc_s > EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP AT TIME ZONE ${${sys.timezone}})) 
        AND timestamp_utc_s < EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP AT TIME ZONE ${${sys.timezone}}))
        AND resource_id NOT IN (SELECT resource_id FROM filtered_terminated_resources)
    ) AS op3,
    (
    SELECT
        COUNT(DISTINCT lt.resource_id) AS terminated
    FROM
        latest_timestamps lt
    WHERE
        lt.max_ts < EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP AT TIME ZONE ${${sys.timezone}})) - 3600
    ) AS op4

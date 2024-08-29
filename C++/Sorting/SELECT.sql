SELECT 
    op1.existing AS "existing", 
    op2.running AS "running", 
    op3.unavailable AS "inactive",
    op4.terminated AS "terminated"
FROM 
    (WITH latest_timestamps AS (
    SELECT
        resource_id,
        MAX(timestamp_utc_s) AS max_ts
    FROM
        cloud_azure_virtual_machines
    WHERE
        timestamp_utc_s > EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}})) 
        AND timestamp_utc_s < EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}}))
        AND ${collection_policy_name IN (${monSvcAzureConfig})}
        AND ${resource_group IN (${monSvcAzureGroup})}
        AND ${subscription_id IN (${monSvcAzureSubscription})}
        AND ${tags LIKE '%' || ((${monSvcVMsTags})) || '%'}
    GROUP BY
        resource_id
    ),
    filtered_terminated_resources AS (
        SELECT
            resource_id
        FROM
            latest_timestamps
        WHERE
            max_ts < EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}}    )) - 3600
    )SELECT count(DISTINCT resource_name) AS existing
     FROM cloud_azure_virtual_machines cavm 
     WHERE timestamp_utc_s > (EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
       AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
       AND ${resource_name IN (${monSvcAzureVMResource})} 
       AND ${collection_policy_name IN (${monSvcAzureConfig})} 
       AND ${resource_group IN (${monSvcAzureGroup})} 
       AND ${subscription_id IN (${monSvcAzureSubscription})} 
       AND ${tags LIKE '%' || ((${monSvcVMsTags})) || '%'}
       AND resource_id NOT IN (SELECT resource_id FROM filtered_terminated_resources)
    ) AS op1,
    (SELECT count(DISTINCT resource_name) AS running
     FROM cloud_azure_virtual_machines cavm 
     WHERE state = 'active' 
       AND timestamp_utc_s > (EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
       AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
       AND ${resource_name IN (${monSvcAzureVMResource})} 
       AND ${collection_policy_name IN (${monSvcAzureConfig})} 
       AND ${resource_group IN (${monSvcAzureGroup})} 
       AND ${subscription_id IN (${monSvcAzureSubscription})} 
       AND ${tags LIKE '%' || ((${monSvcVMsTags})) || '%'}
    ) AS op2,
    (SELECT count(DISTINCT resource_name) AS unavailable
     FROM cloud_azure_virtual_machines cavm 
     WHERE state = 'inactive' 
       AND timestamp_utc_s > (EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
       AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
       AND ${resource_name IN (${monSvcAzureVMResource})} 
       AND ${collection_policy_name IN (${monSvcAzureConfig})} 
       AND ${resource_group IN (${monSvcAzureGroup})} 
       AND ${subscription_id IN (${monSvcAzureSubscription})} 
       AND ${tags LIKE '%' || ((${monSvcVMsTags})) || '%'}
    ) AS op3,
    (WITH latest_timestamps AS (
    SELECT
        resource_name,
        MAX(timestamp_utc_s) AS max_ts
    FROM
        cloud_azure_virtual_machines
    WHERE
        timestamp_utc_s > EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}})) 
        AND timestamp_utc_s < EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}}))
        AND ${resource_name IN (${monSvcAzureVMResource})}
        AND ${collection_policy_name IN (${monSvcAzureConfig})}
        AND ${resource_group IN (${monSvcAzureGroup})}
        AND ${subscription_id IN (${monSvcAzureSubscription})}
        AND ${tags LIKE '%' || ((${monSvcVMsTags})) || '%'}
    GROUP BY
        resource_name
    )
    SELECT
        COUNT(DISTINCT lt.resource_name) AS terminated
    FROM
        latest_timestamps lt
    WHERE
        lt.max_ts < EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})) - 3600

        ) AS op4
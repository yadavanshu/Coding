WITH STORAGE_UTIL_CTE AS (
    SELECT 
EXTRACT(epoch from timestamp::TIMESTAMPTZ)*1000 as timestamp,
ROUND((storage_space_used_mb_avg/TOTAL_METRIC_SAMPLES), 2)::FLOAT as "Used Storage",
Name
FROM (SELECT DISTINCT TIME_SLICE(to_timestamp_tz(timestamp_utc_s), 
(select case when time_diff <= 60 then 5 when time_diff <= 60 * 2 then 5 when time_diff <= 60 * 12 then 5 when time_diff <= 60 * 24 then 5 
when time_diff <= 60 * 48 then 5 when time_diff <= 60 * 168 then 5 when time_diff <= 60 * 720 then 5 when
time_diff <= 60 * 2160 then 5 else 5 end as granularity from (select ((((EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP))/1000)
- ((EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP))/1000))/ 60) as time_diff) AS time_diff_mins), 'MINUTE', 'END') AS timestamp,
AVG(sqldb_1.virtual_core_count_avg) AS virtual_core_count_avg,
AVG(sqldb_1.storage_space_used_mb_avg) AS storage_space_used_mb_avg,
AVG(sqldb_1.io_req_count_avg) AS io_req_count_avg,
AVG(sqldb_1.io_read_b_avg) AS io_read_b_avg,
AVG(sqldb_1.io_written_b_avg) AS io_written_b_avg,
AVG(sqldb_1.avg_cpu_pct_avg) AS avg_cpu_pct_avg,
COUNT(sqldb_1.timestamp_utc_s) AS TOTAL_METRIC_SAMPLES,
sqldb_1.resource_name as Name,
sqldb_2.resource_id as resource_id
FROM cloud_azure_sqlmanagedinstance as sqldb_1,
(Select sqldb.resource_id
from cloud_azure_sqlmanagedinstance sqldb
join
(Select resource_id, max(timestamp_utc_s) as max_ts 
from cloud_azure_sqlmanagedinstance
where resource_id IS NOT NULL 
AND timestamp_utc_s > (EXTRACT(epoch FROM  (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
group by resource_id) as tempt_sqldb
on tempt_sqldb.resource_id = sqldb.resource_id
AND sqldb.timestamp_utc_s = tempt_sqldb.max_ts
GROUP BY sqldb.resource_id) as sqldb_2
Where sqldb_1.resource_id = sqldb_2.resource_id 
AND timestamp_utc_s > (EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
GROUP BY timestamp, sqldb_2.resource_id, sqldb_1.resource_name
ORDER BY timestamp 
) AS TABLE1
ORDER BY timestamp
)
Select * from STORAGE_UTIL_CTE


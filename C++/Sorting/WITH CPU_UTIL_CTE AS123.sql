WITH CPU_UTIL_CTE AS 
(SELECT 
EXTRACT(epoch from timestamp::TIMESTAMPTZ)*1000 as timestamp,
'CPU' as metric,
ROUND((avg_cpu_pct_avg/TOTAL_METRIC_SAMPLES), 2)::FLOAT as metric_value,
name
FROM (SELECT DISTINCT TIME_SLICE(to_timestamp_tz(timestamp_utc_s), 
(select case when time_diff <= 60 then 5 when time_diff <= 60 * 2 then 5 when time_diff <= 60 * 12 then 5 when time_diff <= 60 * 24 then 5 
when time_diff <= 60 * 48 then 5 when time_diff <= 60 * 168 then 5 when time_diff <= 60 * 720 then 5 when
time_diff <= 60 * 2160 then 5 else 5 end as granularity from (select ((((EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP))/1000)
- ((EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP))/1000))/ 60) as time_diff) AS time_diff_mins), 'MINUTE', 'END') AS timestamp,
AVG(sqlmi_1.avg_cpu_pct_avg) AS avg_cpu_pct_avg,
COUNT(sqlmi_1.timestamp_utc_s) AS TOTAL_METRIC_SAMPLES,
sqlmi_1.resource_name as name,
sqlmi_2.resource_id as resource_id
FROM cloud_azure_sqlmanagedinstance as sqlmi_1,
(Select sqlmi.resource_id
from cloud_azure_sqlmanagedinstance sqlmi
join
(Select resource_id, max(timestamp_utc_s) as max_ts 
from cloud_azure_sqlmanagedinstance
where resource_id IS NOT NULL
AND avg_cpu_pct_avg IS NOT NULL
AND timestamp_utc_s > (EXTRACT(epoch FROM  (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
group by resource_id) as tempt_sqlmi
on tempt_sqlmi.resource_id = sqlmi.resource_id
AND sqlmi.timestamp_utc_s = tempt_sqlmi.max_ts
GROUP BY sqlmi.resource_id) as sqlmi_2
Where sqlmi_1.resource_id = sqlmi_2.resource_id 
AND timestamp_utc_s > (EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
GROUP BY timestamp, sqlmi_2.resource_id, sqlmi_1.resource_name
ORDER BY timestamp 
) AS TABLE1
ORDER BY timestamp),

STORAGE_UTIL_CTE AS
(SELECT 
EXTRACT(epoch from timestamp::TIMESTAMPTZ)*1000 as timestamp,
'Used Storage' as metric,
ROUND((storage_space_used_mb_avg/TOTAL_METRIC_SAMPLES), 2)::FLOAT as metric_value,
name
FROM (SELECT DISTINCT TIME_SLICE(to_timestamp_tz(timestamp_utc_s), 
(select case when time_diff <= 60 then 5 when time_diff <= 60 * 2 then 5 when time_diff <= 60 * 12 then 5 when time_diff <= 60 * 24 then 5 
when time_diff <= 60 * 48 then 5 when time_diff <= 60 * 168 then 5 when time_diff <= 60 * 720 then 5 when
time_diff <= 60 * 2160 then 5 else 5 end as granularity from (select ((((EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP))/1000)
- ((EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP))/1000))/ 60) as time_diff) AS time_diff_mins), 'MINUTE', 'END') AS timestamp,
AVG(sqlmi_1.storage_space_used_mb_avg) AS storage_space_used_mb_avg,
COUNT(sqlmi_1.timestamp_utc_s) AS TOTAL_METRIC_SAMPLES,
sqlmi_1.resource_name as name,
sqlmi_2.resource_id as resource_id
FROM cloud_azure_sqlmanagedinstance as sqlmi_1,
(Select sqlmi.resource_id
from cloud_azure_sqlmanagedinstance sqlmi
join
(Select resource_id, max(timestamp_utc_s) as max_ts 
from cloud_azure_sqlmanagedinstance
where resource_id IS NOT NULL
AND storage_space_used_mb_avg IS NOT NULL
AND timestamp_utc_s > (EXTRACT(epoch FROM  (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
group by resource_id) as tempt_sqlmi
on tempt_sqlmi.resource_id = sqlmi.resource_id
AND sqlmi.timestamp_utc_s = tempt_sqlmi.max_ts
GROUP BY sqlmi.resource_id) as sqlmi_2
Where sqlmi_1.resource_id = sqlmi_2.resource_id 
AND timestamp_utc_s > (EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
GROUP BY timestamp, sqlmi_2.resource_id, sqlmi_1.resource_name
ORDER BY timestamp 
) AS TABLE1
ORDER BY timestamp),

IO_WRITE_CTE(SELECT 
EXTRACT(epoch from timestamp::TIMESTAMPTZ)*1000 as timestamp,
'IO Write' as metric,
ROUND((io_written_b_avg/TOTAL_METRIC_SAMPLES), 2)::FLOAT as metric_value,
name
FROM (SELECT DISTINCT TIME_SLICE(to_timestamp_tz(timestamp_utc_s), 
(select case when time_diff <= 60 then 5 when time_diff <= 60 * 2 then 5 when time_diff <= 60 * 12 then 5 when time_diff <= 60 * 24 then 5 
when time_diff <= 60 * 48 then 5 when time_diff <= 60 * 168 then 5 when time_diff <= 60 * 720 then 5 when
time_diff <= 60 * 2160 then 5 else 5 end as granularity from (select ((((EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP))/1000)
- ((EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP))/1000))/ 60) as time_diff) AS time_diff_mins), 'MINUTE', 'END') AS timestamp,
AVG(sqlmi_1.io_written_b_avg) AS io_written_b_avg,
COUNT(sqlmi_1.timestamp_utc_s) AS TOTAL_METRIC_SAMPLES,
sqlmi_1.resource_name as name,
sqlmi_2.resource_id as resource_id
FROM cloud_azure_sqlmanagedinstance as sqlmi_1,
(Select sqlmi.resource_id
from cloud_azure_sqlmanagedinstance sqlmi
join
(Select resource_id, max(timestamp_utc_s) as max_ts 
from cloud_azure_sqlmanagedinstance
where resource_id IS NOT NULL
AND io_written_b_avg IS NOT NULL
AND timestamp_utc_s > (EXTRACT(epoch FROM  (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
group by resource_id) as tempt_sqlmi
on tempt_sqlmi.resource_id = sqlmi.resource_id
AND sqlmi.timestamp_utc_s = tempt_sqlmi.max_ts
GROUP BY sqlmi.resource_id) as sqlmi_2
Where sqlmi_1.resource_id = sqlmi_2.resource_id 
AND timestamp_utc_s > (EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
GROUP BY timestamp, sqlmi_2.resource_id, sqlmi_1.resource_name
ORDER BY timestamp 
) AS TABLE1
ORDER BY timestamp
),

IO_READ_CTE AS (
SELECT 
EXTRACT(epoch from timestamp::TIMESTAMPTZ)*1000 as timestamp,
'IO Read' as metric,
ROUND((io_read_b_avgio_req_count_avg/TOTAL_METRIC_SAMPLES), 2)::FLOAT as metric_value,
name
FROM (SELECT DISTINCT TIME_SLICE(to_timestamp_tz(timestamp_utc_s), 
(select case when time_diff <= 60 then 5 when time_diff <= 60 * 2 then 5 when time_diff <= 60 * 12 then 5 when time_diff <= 60 * 24 then 5 
when time_diff <= 60 * 48 then 5 when time_diff <= 60 * 168 then 5 when time_diff <= 60 * 720 then 5 when
time_diff <= 60 * 2160 then 5 else 5 end as granularity from (select ((((EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP))/1000)
- ((EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP))/1000))/ 60) as time_diff) AS time_diff_mins), 'MINUTE', 'END') AS timestamp,
AVG(sqlmi_1.io_read_b_avgio_req_count_avg) AS io_read_b_avgio_req_count_avg,
COUNT(sqlmi_1.timestamp_utc_s) AS TOTAL_METRIC_SAMPLES,
sqlmi_1.resource_name as name,
sqlmi_2.resource_id as resource_id
FROM cloud_azure_sqlmanagedinstance as sqlmi_1,
(Select sqlmi.resource_id
from cloud_azure_sqlmanagedinstance sqlmi
join
(Select resource_id, max(timestamp_utc_s) as max_ts 
from cloud_azure_sqlmanagedinstance
where resource_id IS NOT NULL
AND io_read_b_avgio_req_count_avg IS NOT NULL
AND timestamp_utc_s > (EXTRACT(epoch FROM  (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
group by resource_id) as tempt_sqlmi
on tempt_sqlmi.resource_id = sqlmi.resource_id
AND sqlmi.timestamp_utc_s = tempt_sqlmi.max_ts
GROUP BY sqlmi.resource_id) as sqlmi_2
Where sqlmi_1.resource_id = sqlmi_2.resource_id 
AND timestamp_utc_s > (EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
GROUP BY timestamp, sqlmi_2.resource_id, sqlmi_1.resource_name
ORDER BY timestamp 
) AS TABLE1
ORDER BY timestamp
),

IO_REQUEST_CTE AS (
SELECT 
EXTRACT(epoch from timestamp::TIMESTAMPTZ)*1000 as timestamp,
'IO Request' as metric,
ROUND((io_req_count_avg/TOTAL_METRIC_SAMPLES), 2)::FLOAT as metric_value,
name
FROM (SELECT DISTINCT TIME_SLICE(to_timestamp_tz(timestamp_utc_s), 
(select case when time_diff <= 60 then 5 when time_diff <= 60 * 2 then 5 when time_diff <= 60 * 12 then 5 when time_diff <= 60 * 24 then 5 
when time_diff <= 60 * 48 then 5 when time_diff <= 60 * 168 then 5 when time_diff <= 60 * 720 then 5 when
time_diff <= 60 * 2160 then 5 else 5 end as granularity from (select ((((EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP))/1000)
- ((EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP))/1000))/ 60) as time_diff) AS time_diff_mins), 'MINUTE', 'END') AS timestamp,
AVG(sqlmi_1.io_req_count_avg) AS io_req_count_avg,
COUNT(sqlmi_1.timestamp_utc_s) AS TOTAL_METRIC_SAMPLES,
sqlmi_1.resource_name as name,
sqlmi_2.resource_id as resource_id
FROM cloud_azure_sqlmanagedinstance as sqlmi_1,
(Select sqlmi.resource_id
from cloud_azure_sqlmanagedinstance sqlmi
join
(Select resource_id, max(timestamp_utc_s) as max_ts 
from cloud_azure_sqlmanagedinstance
where resource_id IS NOT NULL
AND io_req_count_avg IS NOT NULL
AND timestamp_utc_s > (EXTRACT(epoch FROM  (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
group by resource_id) as tempt_sqlmi
on tempt_sqlmi.resource_id = sqlmi.resource_id
AND sqlmi.timestamp_utc_s = tempt_sqlmi.max_ts
GROUP BY sqlmi.resource_id) as sqlmi_2
Where sqlmi_1.resource_id = sqlmi_2.resource_id 
AND timestamp_utc_s > (EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
GROUP BY timestamp, sqlmi_2.resource_id, sqlmi_1.resource_name
ORDER BY timestamp 
) AS TABLE1
ORDER BY timestamp
),

VIRTUAL_CORE_CTE AS (
SELECT 
EXTRACT(epoch from timestamp::TIMESTAMPTZ)*1000 as timestamp,
'Virtual Cores' as metric,
ROUND((virtual_core_count_avg/TOTAL_METRIC_SAMPLES), 2)::FLOAT as metric_value,
name
FROM (SELECT DISTINCT TIME_SLICE(to_timestamp_tz(timestamp_utc_s), 
(select case when time_diff <= 60 then 5 when time_diff <= 60 * 2 then 5 when time_diff <= 60 * 12 then 5 when time_diff <= 60 * 24 then 5 
when time_diff <= 60 * 48 then 5 when time_diff <= 60 * 168 then 5 when time_diff <= 60 * 720 then 5 when
time_diff <= 60 * 2160 then 5 else 5 end as granularity from (select ((((EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP))/1000)
- ((EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP))/1000))/ 60) as time_diff) AS time_diff_mins), 'MINUTE', 'END') AS timestamp,
AVG(sqlmi_1.virtual_core_count_avg) AS virtual_core_count_avg,
COUNT(sqlmi_1.timestamp_utc_s) AS TOTAL_METRIC_SAMPLES,
sqlmi_1.resource_name as name,
sqlmi_2.resource_id as resource_id
FROM cloud_azure_sqlmanagedinstance as sqlmi_1,
(Select sqlmi.resource_id
from cloud_azure_sqlmanagedinstance sqlmi
join
(Select resource_id, max(timestamp_utc_s) as max_ts 
from cloud_azure_sqlmanagedinstance
where resource_id IS NOT NULL
AND virtual_core_count_avg IS NOT NULL
AND timestamp_utc_s > (EXTRACT(epoch FROM  (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
group by resource_id) as tempt_sqlmi
on tempt_sqlmi.resource_id = sqlmi.resource_id
AND sqlmi.timestamp_utc_s = tempt_sqlmi.max_ts
GROUP BY sqlmi.resource_id) as sqlmi_2
Where sqlmi_1.resource_id = sqlmi_2.resource_id 
AND timestamp_utc_s > (EXTRACT(epoch FROM (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})} 
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
GROUP BY timestamp, sqlmi_2.resource_id, sqlmi_1.resource_name
ORDER BY timestamp 
) AS TABLE1
ORDER BY timestamp
)

Select * from STORAGE_UTIL_CTE
UNION ALL
Select * from IO_WRITE_CTE
UNION ALL
Select * from IO_READ_CTE 
UNION ALL
Select * from IO_REQUEST_CTE
UNION ALL
Select * from VIRTUAL_CORE_CTE
UNION ALL
Select * from CPU_UTIL_CTE

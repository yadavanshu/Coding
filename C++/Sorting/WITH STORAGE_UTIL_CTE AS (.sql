WITH STORAGE_UTIL_CTE AS (
    Select mi.resource_name as Name,
    ROUND(virtual_core_count_avg, 2) AS vcore,
    ROUND(storage_space_used_mb_avg, 2) AS used_storage,
    ROUND(io_req_count_avg, 2) AS io_request,
    ROUND(io_read_b_avg, 2) AS io_read,
    ROUND(io_written_b_avg, 2) AS io_write,
    'Storage' as metric
    from cloud_azure_sqlmanagedinstance mi
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
    group by resource_id) as tempt_mi
    on tempt_mi.resource_id = mi.resource_id
    AND mi.timestamp_utc_s = tempt_mi.max_ts
    GROUP BY mi.resource_name, virtual_core_count_avg, storage_space_used_mb_avg,io_req_count_avg, io_read_b_avg, io_written_b_avg
    ORDER BY storage_space_used_mb_avg DESC LIMIT 10
),

IO_READ_CTE AS (
    Select mi.resource_name as Name,
    ROUND(virtual_core_count_avg, 2) AS vcore,
    ROUND(storage_space_used_mb_avg, 2) AS used_storage,
    ROUND(io_req_count_avg, 2) AS io_request,
    ROUND(io_read_b_avg, 2) AS io_read,
    ROUND(io_written_b_avg, 2) AS io_write,
    'IO Read' as metric
    from cloud_azure_sqlmanagedinstance mi
    join
    (Select resource_id, max(timestamp_utc_s) as max_ts 
    from cloud_azure_sqlmanagedinstance
    where resource_id IS NOT NULL 
    AND io_read_b_avg IS NOT NULL
    AND timestamp_utc_s > (EXTRACT(epoch FROM  (${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))) 
    AND timestamp_utc_s < (EXTRACT(epoch FROM (${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}})))
    AND ${collection_policy_name IN (${monSvcAzureConfig})} 
    AND ${resource_group IN (${monSvcAzureGroup})} 
    AND ${subscription_id IN (${monSvcAzureSubscription})} 
    AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
    group by resource_id) as tempt_mi
    on tempt_mi.resource_id = mi.resource_id
    AND mi.timestamp_utc_s = tempt_mi.max_ts
    GROUP BY mi.resource_name, virtual_core_count_avg, storage_space_used_mb_avg,io_req_count_avg, io_read_b_avg, io_written_b_avg
    ORDER BY io_read_b_avg DESC LIMIT 10
),
IO_WRITE_CTE AS (
    Select mi.resource_name as Name,
    ROUND(virtual_core_count_avg, 2) AS vcore,
    ROUND(storage_space_used_mb_avg, 2) AS used_storage,
    ROUND(io_req_count_avg, 2) AS io_request,
    ROUND(io_read_b_avg, 2) AS io_read,
    ROUND(io_written_b_avg, 2) AS io_write,
    'IO Write' as metric
    from cloud_azure_sqlmanagedinstance mi
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
    group by resource_id) as tempt_mi
    on tempt_mi.resource_id = mi.resource_id
    AND mi.timestamp_utc_s = tempt_mi.max_ts
    GROUP BY mi.resource_name, virtual_core_count_avg, storage_space_used_mb_avg,io_req_count_avg, io_read_b_avg, io_written_b_avg
    ORDER BY io_written_b_avg DESC LIMIT 10
),
IO_REQUEST_CTE AS (
    Select mi.resource_name as Name,
    ROUND(virtual_core_count_avg, 2) AS vcore,
    ROUND(storage_space_used_mb_avg, 2) AS used_storage,
    ROUND(io_req_count_avg, 2) AS io_request,
    ROUND(io_read_b_avg, 2) AS io_read,
    ROUND(io_written_b_avg, 2) AS io_write,
    'IO Request' as metric
    from cloud_azure_sqlmanagedinstance mi
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
    group by resource_id) as tempt_mi
    on tempt_mi.resource_id = mi.resource_id
    AND mi.timestamp_utc_s = tempt_mi.max_ts
    GROUP BY mi.resource_name, virtual_core_count_avg, storage_space_used_mb_avg,io_req_count_avg, io_read_b_avg, io_written_b_avg
    ORDER BY io_req_count_avg DESC LIMIT 10
),

VIRTUAL_CORE_CTE AS (
    Select mi.resource_name as Name,
    ROUND(virtual_core_count_avg, 2) AS vcore,
    ROUND(storage_space_used_mb_avg, 2) AS used_storage,
    ROUND(io_req_count_avg, 2) AS io_request,
    ROUND(io_read_b_avg, 2) AS io_read,
    ROUND(io_written_b_avg, 2) AS io_write,
    'Virtual Cores' as metric
    from cloud_azure_sqlmanagedinstance mi
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
    group by resource_id) as tempt_mi
    on tempt_mi.resource_id = mi.resource_id
    AND mi.timestamp_utc_s = tempt_mi.max_ts
    GROUP BY mi.resource_name, virtual_core_count_avg, storage_space_used_mb_avg,io_req_count_avg, io_read_b_avg, io_written_b_avg
    ORDER BY virtual_core_count_avg DESC LIMIT 10
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

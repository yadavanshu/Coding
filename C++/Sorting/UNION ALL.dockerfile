UNION ALL
SELECT 'Storage' as metric
FROM cloud_azure_sqlmanagedinstance 
where 
timestamp_utc_s > (EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))
AND timestamp_utc_s < (EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}} )) 
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})}
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'}  
group by metric
UNION
SELECT 'Virtual Cores' as metric
FROM cloud_azure_sqlmanagedinstance 
where 
timestamp_utc_s > (EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))
AND timestamp_utc_s < (EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}} )) 
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})}
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
group by metric
UNION ALL
SELECT 'IO Request' as metric
FROM cloud_azure_sqlmanagedinstance 
where 
timestamp_utc_s > (EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))
AND timestamp_utc_s < (EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}} )) 
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})}
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'}  
group by metric
UNION
SELECT 'IO Read' as metric
FROM cloud_azure_sqlmanagedinstance 
where 
timestamp_utc_s > (EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))
AND timestamp_utc_s < (EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}} )) 
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})}
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'} 
group by metric
UNION ALL
SELECT 'IO Wrtie' as metric
FROM cloud_azure_sqlmanagedinstance 
where 
timestamp_utc_s > (EXTRACT(epoch FROM ${${Calendar:start}}::TIMESTAMP at timezone ${${sys.timezone}}))
AND timestamp_utc_s < (EXTRACT(epoch FROM ${${Calendar:end}}::TIMESTAMP at timezone ${${sys.timezone}} )) 
AND ${collection_policy_name IN (${monSvcAzureConfig})} 
AND ${resource_group IN (${monSvcAzureGroup})} 
AND ${subscription_id IN (${monSvcAzureSubscription})}
AND ${tags LIKE '%' || ((${monSvcSqlMITags})) || '%'}  
group by metric

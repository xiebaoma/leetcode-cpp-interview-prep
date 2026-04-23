# xiebaoma
# 2025-08-04

select 
	player_id, device_id
from 
(
    select 
    	player_id, 
    	device_id, 
    	dense_rank() over(partition by player_id 
                          order by event_date asc) rnk 
   	from activity
) a where rnk=1

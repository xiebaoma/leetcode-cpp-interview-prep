# xiebaoma
# 2025-08-04

SELECT
  A.player_id,
  MIN(A.event_date) AS first_login
FROM
  Activity A
GROUP BY
  A.player_id;

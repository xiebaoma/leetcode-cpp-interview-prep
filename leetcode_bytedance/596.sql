# xiebaoma
# 2025-08-24

SELECT
    class
FROM
    (SELECT
        class, COUNT(student) AS num
    FROM
        courses
    GROUP BY class) AS temp_table
WHERE
    num >= 5
;

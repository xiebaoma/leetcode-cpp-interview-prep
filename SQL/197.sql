# xiebaoma
# 2025-08-03

select b.id
    from 
        Weather a,Weather b
    where a.Temperature<b.Temperature
    and date_add(a.recordDate,interval 1 day)=b.recordDate;
# xiebaoma
# 2025-10-27

select sales.product_id as product_id, product.product_name as product_name
from sales left join product on sales.product_id = product.product_id
group by product_id
having count(sale_date between '2019-01-01' and '2019-03-31' or null) = count(*)

# Write your MySQL query statement below
# update salary set sex = 
# case sex 
# when 'm' then 'f'
# else 'm'
# end;

# Approach-2: 
update salary set sex= 
case when sex='f' then 'm'
when sex='m' then 'f'
end;
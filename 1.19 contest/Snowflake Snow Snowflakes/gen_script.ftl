<#assign max_n = 100000 />
<#assign min_val = 0 />
<#assign max_val = 10000000 />

gen -n ${max_n} -min_val ${max_val} -max_val ${max_val} -rand false > $
gen -n ${max_n} -min_val ${min_val} -max_val ${max_val} -rand false > $
gen -n 1 -min_val 0 -max_val 0 -rand false > $

<#list 1..10 as i>
    gen -rand true -n ${max_n} ${i} > $
</#list>
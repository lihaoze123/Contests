<#-- 小数据 -->
gen -n 10 -q 10 -minLen 1 -maxLen 5 -type 1 1 > $
gen -n 10 -q 10 -minLen 1 -maxLen 5 -type 2 2 > $

<#-- 中等数据 -->
gen -n 100 -q 100 -minLen 3 -maxLen 10 -type 1 3 > $
gen -n 100 -q 100 -minLen 3 -maxLen 10 -type 2 4 > $

<#-- 大数据随机 -->
gen -n 10000 -q 10000 -minLen 1 -maxLen 20 -type 1 5 > $
gen -n 10000 -q 10000 -minLen 10 -maxLen 20 -type 1 6 > $

<#-- 大数据带前缀 -->
gen -n 10000 -q 10000 -minLen 5 -maxLen 20 -type 2 7 > $
gen -n 10000 -q 10000 -minLen 15 -maxLen 20 -type 2 8 > $

<#-- 极限数据 -->
gen -n 10000 -q 10000 -minLen 20 -maxLen 20 -type 1 9 > $
gen -n 10000 -q 10000 -minLen 20 -maxLen 20 -type 2 10 > $ 
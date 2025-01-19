<#assign max_n = 100000 />
<#assign max_m = 100000 />
<#assign mid_n = 1000 />
<#assign mid_m = 1000 />
<#assign small_n = 10 />
<#assign small_m = 10 />

gen -n ${small_n} -m ${small_m} -mode random 1 > $
gen -n ${small_n} -m ${small_m} -mode all_same 2 > $
gen -n ${small_n} -m ${small_m} -mode all_different 3 > $
gen -n ${small_n} -m ${small_m} -mode same_substrings 4 > $

gen -n ${mid_n} -m ${mid_m} -mode random 5 > $
gen -n ${mid_n} -m ${mid_m} -mode all_same 6 > $
gen -n ${mid_n} -m ${mid_m} -mode all_different 7 > $
gen -n ${mid_n} -m ${mid_m} -mode same_substrings 8 > $

gen -n ${max_n} -m ${max_m} -mode random 9 > $
gen -n ${max_n} -m ${max_m} -mode all_same 10 > $
gen -n ${max_n} -m ${max_m} -mode all_different 11 > $
gen -n ${max_n} -m ${max_m} -mode same_substrings 12 > $

gen -n ${max_n} -m ${small_m} -mode random 13 > $
gen -n ${small_n} -m ${max_m} -mode random 14 > $

gen -n 50000 -m 50000 -mode random 15 > $
gen -n 33333 -m 33333 -mode random 16 > $
gen -n 25000 -m 25000 -mode random 17 > $
gen -n 20000 -m 20000 -mode random 18 > $
gen -n 16666 -m 16666 -mode random 19 > $ 
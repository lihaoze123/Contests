<#-- Small tests -->
gen -n 5 -maxlen 5 -type 1 1 > $
gen -n 10 -maxlen 10 -type 1 2 > $
gen -n 20 -maxlen 15 -type 1 3 > $
<#-- Medium tests -->
gen -n 50 -maxlen 20 -type 1 4 > $
gen -n 100 -maxlen 30 -type 1 5 > $
gen -n 200 -maxlen 40 -type 1 6 > $
<#-- Large tests -->
gen -n 300 -maxlen 50 -type 1 7 > $
gen -n 400 -maxlen 60 -type 1 8 > $
<#-- Special tests -->
gen -n 300 -maxlen 50 -type 2 9 > $
gen -n 400 -maxlen 60 -type 2 10 > $

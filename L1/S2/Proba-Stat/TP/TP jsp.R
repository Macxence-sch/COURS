ascoeur=7

nsmin=10
res_X=c(rep(0,nsim))


for (i in 1:nsmin){
  X=sample.int(32,32,replace=FALSE)
  print(X)
    for (j in 1:32){
      if (X[j]==ascoeur) res_X[i]=j
    }
}

print(res_X)


    double a[n],x[n],y[n],b[n],z[n]; 
    // ...
    
    // unroll
    for (i=0; i<n - n%m; i++){
        a[i]=x[i]+y[i]*sin((i%8)*M_PI);

        a[i+1]= ...
        ...
        a[i+m-1] = ...
        // aproveitar o valor de x[i] recèm utilizado p/ calcular b[i]
        b[i]=1.0/x[i]+z[i];

        b[i+1]= ...
        ...
        b[i+m-1] = ...
    } 

    // jam
    for (int i = n - n%m; i < n; i++){
        a[i]=x[i]+y[i]*sin((i%8)*M_PI);
    }


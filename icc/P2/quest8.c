    double a[nd1][nd2], y[nd2], x[nd1]
     ...
    for (long i=0; i < nd2; ++i){
        y[i] = 0.0;
        
        for (long j=0; j < nd1; ++j){
            y[i] = y[i] + a[j][i]*x[j];
            // y[i] é o valor da COL de a pelo vet x 
        }
    }



    double a[nd1][nd2], y[nd2], x[nd1]
    ...
    
    // cria a com 0.0
    for (int i=0; i < nd2; ++i){
        y[i] = 0.0f;
    }

    for (int j=0; j < nd1; ++j){
        // double t = 0.0;
        // zero o valor de y[j] antes para não sobreescrever 0 em um valor já calculado
        for (int i=0; i < nd2; ++i){
            //Multiplico a  linha inteira por x[j]
            y[i] = y[i] + a[j][i]*x[j];
        }
    }
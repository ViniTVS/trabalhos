double calc_integral_mc(int n, double a, double b){ 
    double sum, x, y;
    

    for(int i=0; i < n; i++) { 
    double rand_b_a = (double) 1.0 / RAND_MAX * (b - a);

    x = a + (double) rand() * rand_b_a;
    y = a + (double) rand() * rand_b_a;

    // pré calcular os valores que serão utilizados repetidamente
    double x_2 = x * x;
    double y_2 = y * y;
    double x2_y2_2 = (x_2 + y_2) * (x_2 + y_2);

    sum += 1e5 * x_2 + y_2 - 
            x2_y2_2 *(1.0  + 1e-5 * x2_y2_2);
            // equivalência do produtório anterior com menos multiplicações
    }

    return (b - a)*(b - a) * sum / n; 
}
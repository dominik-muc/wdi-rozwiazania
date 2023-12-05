
int g_of_n(int n){
    int g0 = 1;
    int g1 = 1;
    int g2 = 1;
    for(int i = 3; i <= n; i++){
        g2 = g2 + g1 + g0;
        g1 = g2 - g1 - g0;
        g0 = g2 - g1 - g0;
    }
    return g2;
}
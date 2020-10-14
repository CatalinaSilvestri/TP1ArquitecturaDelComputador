int main(){
    int a,b;
    a = (0xFE);
    b = -1;
    a += b;
    b++;
    b = 0xFE;
    return a;
}

//Dudas
/*
+Asignacion a los registros, no nos asigna el bl.
    tipo numerico minimo c es shortint
+tamanio de las variables, para poder usar 'b'
*/
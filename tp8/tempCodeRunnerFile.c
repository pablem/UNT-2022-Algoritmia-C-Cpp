    if(A[0].frec <= A[1].frec) {
        minIzq = A[0].frec;
        minDer = A[1].frec;
        p1 = 0;
        p2 = 1;
    } else {
        minIzq = A[1].frec;
        minDer = A[0].frec;
        p1 = 1;
        p2 = 0;
    }
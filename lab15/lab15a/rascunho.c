for (i = 0; i < NDIG-1; i++) {
        if (operadores[i] == 1) {
            aux = (10 * aux) + codigo[i+1];
        }
        else {
            soma += ((operadores[i] - 1) * aux);
            aux = codigo[i+1];
        }
    }
    soma += ((operadores[i] - 1) * aux);
    
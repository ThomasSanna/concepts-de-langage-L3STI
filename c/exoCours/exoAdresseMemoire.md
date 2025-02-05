
```c
int i = 3;
int* pi;
pi = &i;
char c = 'c';
char* pc;
pc = &c;
```

| Objet      | Adresse mémoire | Valeur     |Taille Mémoire|
| ---------- | ---------------- | ---------- |---------|
| i (int)    | 4831836000       | 3          |4oct (32bits)|
| pi (int*)  | 4831836004       | 4831836000 |4o|
| c (char)   | 4831836008       | 'c'        |1o|
| pc (char*) | 4831836009       | 4831836008 |4o|

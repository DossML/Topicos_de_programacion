#ifndef EJ13_H_INCLUDED
#define EJ13_H_INCLUDED

    /*
    a=alta          -> Si encuentro entonces error      /Si no encuentro lo agrego a temp
    b=baja          -> Si encuentro entonces lo borro   /Si no lo encuentro error
    m=modificacion  -> Si encuentro entonces modifico   /Si no encuentro error

    Para los errores usar printf (Temporalmente)

    Condicion de corte -> Hasta que termine el archivo de novedades, recorrer en simultaneo.
    Remove "Archivo.dat" -> Rename "Temporal.dat"
    */

typedef struct
{
    int dni;
    char nombre[20];
    char apellido[20];
    float promedio;

} tAlumno;


typedef struct
{
    int dni;
    char nombre[20];
    char apellido[20];
    double sueldo;

} tEmpl;

typedef struct{
    tEmpl empleado;
    char tipo;
} tNovedad;

int crearLoteEmpl(const char* nom_archv);
int crearLoteAlu(const char* nom_archv);
int crearLoteNovedades(const char* nom_archv);
int cmp_EmplAlu(void* alu, void* empl);
int cmp_NovEmpl(void* nov, void* empl);
int actualizarArchivosEmpl(const char* arch1, const char* arch2, int cmp_EmplAlu(void*, void*));
int mergeEmpleadosNovedades(const char* arch1, const char* arch2, int cmp_NovEmpl(void*, void*));
int mostrarEmpl(char* nombreArch);
int mostrarAlumno(char* nombreArch);
int mostrarNovedades(char* nombreArch);

#endif // EJ13_H_INCLUDED

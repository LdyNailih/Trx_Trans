/* Processed by ecpg (4.7.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "demonio.pgc"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// Incluye el mecanismo de manejo de errores de SQL

#line 1 "/usr/include/postgresql/sqlca.h"
#ifndef POSTGRES_SQLCA_H
#define POSTGRES_SQLCA_H

#ifndef PGDLLIMPORT
#if  defined(WIN32) || defined(__CYGWIN__)
#define PGDLLIMPORT __declspec (dllimport)
#else
#define PGDLLIMPORT
#endif   /* __CYGWIN__ */
#endif   /* PGDLLIMPORT */

#define SQLERRMC_LEN	150

#ifdef __cplusplus
extern		"C"
{
#endif

struct sqlca_t
{
	char		sqlcaid[8];
	long		sqlabc;
	long		sqlcode;
	struct
	{
		int			sqlerrml;
		char		sqlerrmc[SQLERRMC_LEN];
	}			sqlerrm;
	char		sqlerrp[8];
	long		sqlerrd[6];
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows processed				*/
	/* after an INSERT, UPDATE or				*/
	/* DELETE statement					*/
	/* 3: empty						*/
	/* 4: empty						*/
	/* 5: empty						*/
	char		sqlwarn[8];
	/* Element 0: set to 'W' if at least one other is 'W'	*/
	/* 1: if 'W' at least one character string		*/
	/* value was truncated when it was			*/
	/* stored into a host variable.				*/

	/*
	 * 2: if 'W' a (hopefully) non-fatal notice occurred
	 */	/* 3: empty */
	/* 4: empty						*/
	/* 5: empty						*/
	/* 6: empty						*/
	/* 7: empty						*/

	char		sqlstate[5];
};

struct sqlca_t *ECPGget_sqlca(void);

#ifndef POSTGRES_ECPG_INTERNAL
#define sqlca (*ECPGget_sqlca())
#endif

#ifdef __cplusplus
}
#endif

#endif

#line 11 "demonio.pgc"


// Declaracion de variables a usar en SQL
/* exec sql begin declare section */

    
    
    
   //clientes
   
    
    
    
   
    
     
   
   
   //peliculas
    
    
    
    
    
    
   
   
       


#line 16 "demonio.pgc"
  struct varchar_1  { int len; char arr[ 16 ]; }  SQL_dbname ;
 
#line 17 "demonio.pgc"
  struct varchar_2  { int len; char arr[ 16 ]; }  SQL_user ;
 
#line 18 "demonio.pgc"
  struct varchar_3  { int len; char arr[ 9 ]; }  SQL_password ;
 
#line 21 "demonio.pgc"
  struct varchar_4  { int len; char arr[ 21 ]; }  SQL_nombre_usuario ;
 
#line 22 "demonio.pgc"
  struct varchar_5  { int len; char arr[ 21 ]; }  SQL_apellido ;
 
#line 23 "demonio.pgc"
  struct varchar_6  { int len; char arr[ 51 ]; }  SQL_mail ;
 
#line 25 "demonio.pgc"
  struct varchar_7  { int len; char arr[ 9 ]; }  SQL_rut ;
 
#line 26 "demonio.pgc"
  struct varchar_8  { int len; char arr[ 21 ]; }  SQL_clave ;
 
#line 30 "demonio.pgc"
  struct varchar_9  { int len; char arr[ 21 ]; }  SQL_nombre ;
 
#line 31 "demonio.pgc"
  struct varchar_10  { int len; char arr[ 21 ]; }  SQL_genero ;
 
#line 32 "demonio.pgc"
  struct varchar_11  { int len; char arr[ 21 ]; }  SQL_pais ;
 
#line 33 "demonio.pgc"
  struct varchar_12  { int len; char arr[ 5 ]; }  SQL_anio ;
 
#line 34 "demonio.pgc"
  struct varchar_13  { int len; char arr[ 21 ]; }  SQL_stock ;
 
#line 35 "demonio.pgc"
  struct varchar_14  { int len; char arr[ 6 ]; }  SQL_precio ;
 
#line 38 "demonio.pgc"
 int SQL_count ;
/* exec sql end declare section */
#line 40 "demonio.pgc"



// Metodo para conectarse a la BdD
int SQLConectar() {

    strcpy(SQL_dbname.arr, "b17957434_trans");
    SQL_dbname.len = strlen(SQL_dbname.arr);
    strcpy(SQL_user.arr, "b17957434_trans");
    SQL_user.len = strlen(SQL_user.arr);
    strcpy(SQL_password.arr, "dalarcon");
    SQL_password.len = strlen(SQL_password.arr);

    { ECPGconnect(__LINE__, 0, SQL_dbname.arr , SQL_user.arr , SQL_password.arr , NULL, 0); }
#line 54 "demonio.pgc"


    if(sqlca.sqlcode != 0) {
            printf("Error en la conexion con la base de datos\n\n");
            return(0);
    } else {
            printf("Conexion con base de datos realizada\n\n");
            return(1);
    }
}
// Fin SQLConectar()


int main() {

    printf("\n\n ++++++++++   Demonio en ejecucion   ++++++++++\n\n\n");
    printf("Conexion BdD:\n");

    SQLConectar();

    // Se definen variables y estructuras necesarias para la comunicacion 
    // entre el demonio y los .c

    int qid, pid , len;

    struct msgbuf
    {
        long mtype;
        struct
        {
            int pid;
            char datos[2000];
        } texto;
    } mensaje, respuesta;

    qid = msgget (666666, IPC_CREAT|0666);
    pid = getpid ();

    while(1){

        //limpiamos la estructura de mensaje
        memset(&mensaje, 0, sizeof mensaje);

        //Limpiamos la estructura de respuesta
        memset (&respuesta, 0, sizeof respuesta);

        if((len = msgrcv (qid, &mensaje, 2500, 1, 0)) > 0) {

            memset (&respuesta, 0, sizeof respuesta);
            printf("Recibido: (%ld) <%d/%s>\n\n", mensaje.mtype, 
            mensaje.texto.pid, mensaje.texto.datos);
            int pid_destino = mensaje.texto.pid;
        

     // Fomulario del que viene

            char formulario[7];
            memset (formulario, 0, sizeof formulario);
            sscanf(mensaje.texto.datos, "%6c", formulario);
            printf("El formulario es: [%s]\n\n", formulario);


        
/*************************************************************************
                                Formularios
*************************************************************************/

    //FORMULARIO INGRESAR PELICULA
            if (strcmp(formulario, "ingpel")==0){

                printf("   --------------------   \n   El proceso Es: Ingresar Pelicula \n   --------------------\n\n");
                char nombre[21];
                char genero[21];
                char pais[21];
                char anio[5];
                char stock[21];
                char precio[6];
                
            //Limpiamos los Strings
                memset(nombre, 0 , sizeof nombre);
                memset(genero, 0 , sizeof genero);
                memset(pais, 0, sizeof pais);
                memset(anio, 0 , sizeof anio);
                memset(stock, 0, sizeof stock);
                memset(precio, 0, sizeof precio);

            //Recibimos los datos desde el .c
                sscanf(mensaje.texto.datos, "%6c%20c%20c%20c%4c%20c%5c", formulario, nombre,
                genero, pais, anio, stock, precio);

            //Guardamos la variable en la estructura 
                sprintf(SQL_nombre.arr,"%s", nombre);
                SQL_nombre.len=strlen(SQL_nombre.arr);

                sprintf(SQL_genero.arr,"%s", genero);
                SQL_genero.len=strlen(SQL_genero.arr);

                sprintf(SQL_pais.arr,"%s", pais);
                SQL_pais.len=strlen(SQL_pais.arr);

                sprintf(SQL_anio.arr,"%s", anio);
                SQL_anio.len=strlen(SQL_anio.arr);

                sprintf(SQL_stock.arr,"%s", stock);
                SQL_stock.len=strlen(SQL_stock.arr);

                sprintf(SQL_precio.arr,"%s", precio);
                SQL_precio.len=strlen(SQL_precio.arr);
                
                printf("La pelicula es: %s\n", SQL_nombre.arr);
                printf("Genero: %s\n", SQL_genero.arr);
                printf("Pais: %s\n", SQL_pais.arr);
                printf("Anio: %s\n", SQL_anio.arr);
                printf("Stock: %s\n", SQL_stock.arr);
                printf("Precio: %s\n", SQL_precio.arr);
         
             //Verificamos si la  pelicula ya existe
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from PELICULA where NOMBRE = $1 ", 
	ECPGt_varchar,&(SQL_nombre),(long)21,(long)1,sizeof(struct varchar_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 172 "demonio.pgc"


                if( SQL_count != 0)
                {
                    printf("La pelicula ya existe\n");
                    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre from pelicula where genero = $1 ", 
	ECPGt_varchar,&(SQL_genero),(long)21,(long)1,sizeof(struct varchar_10), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombre),(long)21,(long)1,sizeof(struct varchar_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 177 "demonio.pgc"

                    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre from pelicula where pais = $1 ", 
	ECPGt_varchar,&(SQL_pais),(long)21,(long)1,sizeof(struct varchar_11), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombre),(long)21,(long)1,sizeof(struct varchar_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 179 "demonio.pgc"

                    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre from pelicula where anio = $1 ", 
	ECPGt_varchar,&(SQL_anio),(long)5,(long)1,sizeof(struct varchar_12), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombre),(long)21,(long)1,sizeof(struct varchar_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 181 "demonio.pgc"

                    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre from pelicula where stock = $1 ", 
	ECPGt_varchar,&(SQL_stock),(long)21,(long)1,sizeof(struct varchar_13), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombre),(long)21,(long)1,sizeof(struct varchar_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 183 "demonio.pgc"

                    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre from pelicula where precio = $1 ", 
	ECPGt_varchar,&(SQL_precio),(long)6,(long)1,sizeof(struct varchar_14), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombre),(long)21,(long)1,sizeof(struct varchar_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 185 "demonio.pgc"

                    { ECPGtrans(__LINE__, NULL, "commit");}
#line 186 "demonio.pgc"


                    printf("Y sus datos son: Nombre Pelicula:%s,Genero:%s,Pais:%s,Anio:%s,Stock:%s,Precio:%s\n\n",SQL_nombre.arr,SQL_genero.arr,SQL_pais.arr,SQL_anio.arr,SQL_stock.arr,SQL_precio.arr);

                    memset( &respuesta, 0, sizeof respuesta);
                    sprintf(respuesta.texto.datos, "%s", "02");
                    respuesta.mtype = pid_destino;
                    respuesta.texto.pid = pid;
                    msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);
                }
                else{


               // Insertamos la película en la base de datos
                    { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into PELICULA ( nombre , genero , pais , anio , stock , precio ) values ( $1  , $2  , $3  , $4  , $5  , $6  )", 
	ECPGt_varchar,&(SQL_nombre),(long)21,(long)1,sizeof(struct varchar_9), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_genero),(long)21,(long)1,sizeof(struct varchar_10), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_pais),(long)21,(long)1,sizeof(struct varchar_11), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_anio),(long)5,(long)1,sizeof(struct varchar_12), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_stock),(long)21,(long)1,sizeof(struct varchar_13), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_precio),(long)6,(long)1,sizeof(struct varchar_14), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 201 "demonio.pgc"

                    { ECPGtrans(__LINE__, NULL, "commit");}
#line 202 "demonio.pgc"


                // Revisar en caso de error en la consulta
                    if(sqlca.sqlcode != 0) {
                     printf("\nERROR en la consulta SQL\n\n");
                     memset(&respuesta,0,sizeof respuesta);
                        sprintf(respuesta.texto.datos,"%s", "03");
                        respuesta.mtype=pid_destino;
                        respuesta.texto.pid=pid;
                    msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

                    } else {

                   printf("\nPelicula ingresada con exito\n\n");
                   memset(&respuesta,0,sizeof respuesta);
                    sprintf(respuesta.texto.datos, "%s","01");
                    respuesta.mtype=pid_destino;
                    respuesta.texto.pid=pid;
        msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

                } // Fin else

            }
}			//Fin Formulario

    //FORMULARIO LOGIN
   
         if (strcmp(formulario, "loginn")==0){
   printf(" --------------------   \n   El proceso Es: Login\n  -------------------\n\n");
                char rut[8];
                char clave[20];   // cambiar claves
            //Limpiamos los Strings
                memset(rut, 0 , sizeof rut);
                memset(clave, 0 , sizeof clave);

            //Recibimos los datos desde el .c
                sscanf(mensaje.texto.datos, "%6c%8c%20c",formulario, rut,clave); // agregar formulario 

            //Guardamos la variable en la estructura
                sprintf(SQL_rut.arr,"%s", rut);
                SQL_rut.len=strlen(SQL_rut.arr);
                sprintf(SQL_clave.arr,"%s", clave);
                SQL_clave.len=strlen(SQL_clave.arr);

             //Verificamos si el usuario ya existe
                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from usuario where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)9,(long)1,sizeof(struct varchar_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 247 "demonio.pgc"

                memset(&respuesta,0,sizeof respuesta);

                if(SQL_count == 0)
                {
                
                    printf("Faltan campos");
                    memset( &respuesta, 0, sizeof respuesta);
                    sprintf(respuesta.texto.datos, "%s", "03");
                    respuesta.mtype = pid_destino;
                    respuesta.texto.pid = pid;
                    msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);
                   // printf("respuesta.texto.datos");
                    printf("LALALALALALALALALALALALALA");
                }




			} //Fin Formulario
			
			/*************************************************************************
                        Registrar Personas
            *************************************************************************/

                        if (strcmp(formulario, "regist")==0){

                                printf("   --------------------   \n   Registrar personas.\n   --------------------\n\n");

                                char nombre[21];
                                char apellido[21];
                                char rut[9];
                                char mail[51];
                                char clave[21];
                                
                             
                                //Limpiamos los Strings


                                memset (nombre, 0, sizeof nombre);
                                memset (apellido, 0, sizeof apellido);
                                memset (rut, 0, sizeof rut);
                                memset (mail, 0, sizeof mail);
                                memset (clave, 0, sizeof clave);
                                                     

                                //Recibimos los datos desde el .c

                                printf("Recibi: %s\n",mensaje.texto.datos);
                                sscanf(mensaje.texto.datos, "%6c%8c%20c%20c%50c%20c", formulario, rut, nombre, apellido, mail, clave);
                             


                             //Guardamos la variable en la estructura arr de los char
								sprintf(SQL_rut.arr,"%s", rut);
								SQL_rut.len=strlen(SQL_rut.arr);
								
								sprintf(SQL_nombre_usuario.arr,"%s", nombre);
								SQL_nombre_usuario.len=strlen(SQL_nombre_usuario.arr);
								
								sprintf(SQL_apellido.arr,"%s", apellido);
								SQL_apellido.len=strlen(SQL_apellido.arr);
								
								sprintf(SQL_mail.arr,"%s", mail);
								SQL_mail.len=strlen(SQL_mail.arr);
								
								sprintf(SQL_clave.arr,"%s", clave);
								SQL_clave.len=strlen(SQL_clave.arr);

				// Verificamos si el usuario ya esta registrado
				{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from USUARIO where RUT = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)9,(long)1,sizeof(struct varchar_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 317 "demonio.pgc"


				if( SQL_count != 0) {
					
					printf(" ya fue registrado\n");
					
					{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre from USUARIO where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)9,(long)1,sizeof(struct varchar_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombre_usuario),(long)21,(long)1,sizeof(struct varchar_4), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 323 "demonio.pgc"
 
					{ ECPGtrans(__LINE__, NULL, "commit");}
#line 324 "demonio.pgc"

					
  printf("Y sus datos son: Nombre:%s, Rut:%s\n\n", SQL_nombre_usuario.arr, SQL_rut.arr);

					memset( &respuesta, 0, sizeof respuesta);
					sprintf(respuesta.texto.datos, "%s", "01");
					respuesta.mtype = pid_destino;
					respuesta.texto.pid = pid;
					msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);

				} else {


					// Insertamos el alumno en la BdD
                       
                      // printf("Nombre :s\n",SQL_nombre_usuario.arr);
                       // printf("Apellido : s\n",SQL_apellido.arr);
                       // printf("Rut : s\n", SQL_rut.arr);
                       // printf("Mail :s\n",SQL_mail.arr);
                       // printf("Clave : s\n",SQL_clave.arr);


					{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "insert into USUARIO ( rut , nombre , apellido , mail , clave ) values ( $1  , $2  , $3  , $4  , $5  )", 
	ECPGt_varchar,&(SQL_rut),(long)9,(long)1,sizeof(struct varchar_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_nombre_usuario),(long)21,(long)1,sizeof(struct varchar_4), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_apellido),(long)21,(long)1,sizeof(struct varchar_5), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_mail),(long)51,(long)1,sizeof(struct varchar_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_clave),(long)21,(long)1,sizeof(struct varchar_8), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 347 "demonio.pgc"

					{ ECPGtrans(__LINE__, NULL, "commit");}
#line 348 "demonio.pgc"


					// Revisar en caso de error en la consulta
					if(sqlca.sqlcode != 0) {
						
						printf("\nERROR en la consulta SQL\n\n");

						memset(&respuesta,0,sizeof respuesta);
                                                
sprintf(respuesta.texto.datos, "%s", "02");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					} else {			

						printf("\nIngresado con exito\n\n");	
                            	
						memset(&respuesta,0,sizeof respuesta);
	                        		sprintf(respuesta.texto.datos, "%s", "03");
       	                        		respuesta.mtype=pid_destino;
                               	 		respuesta.texto.pid=pid;
                                		msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

					}

				} // Fin else

			}//Fin Formulario regist
			
			/*************************************************************************
				Eliminar Personas 
			*************************************************************************/

                        if (strcmp(formulario, "eliusu")==0){

                                printf("   --------------------   \n   Eliminemos gente! \n   --------------------\n\n");

                                char rut[9];
                             
                                //Limpiamos los Strings

                                memset (rut, 0, sizeof rut);
                                
                                //Recibimos los datos desde el .c

                                printf("Recibi: %s\n",mensaje.texto.datos);
                                sscanf(mensaje.texto.datos, "%6c%8c", formulario, rut);
                             
                             //Guardamos la variable en la estructura arr de los char
								
								sprintf(SQL_rut.arr,"%s", rut);
								SQL_rut.len=strlen(SQL_rut.arr);
								
								printf("El Rut de la Persona es: %s\n", SQL_rut.arr);
								
				// Verificamos si el rut existe.
				
								{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from USUARIO where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)9,(long)1,sizeof(struct varchar_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 406 "demonio.pgc"

				
                                if( SQL_count != 0) {
                                    //Obtenemos datos del cliente a eliminar y limpiamos
                                        
								//Eliminamos el cliente de la BdD
                                        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "delete from USUARIO where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)9,(long)1,sizeof(struct varchar_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 412 "demonio.pgc"

                                        { ECPGtrans(__LINE__, NULL, "commit");}
#line 413 "demonio.pgc"

										
									
									
									memset( &respuesta, 0, sizeof respuesta);
									sprintf(respuesta.texto.datos, "%s", "01");
									respuesta.mtype = pid_destino;
									respuesta.texto.pid = pid;
									msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);
					
					} else {
						
						printf("\n  no existe el rut \n\n");

						memset(&respuesta,0,sizeof respuesta);
                        sprintf(respuesta.texto.datos, "%s", "02");
						respuesta.mtype=pid_destino;
                        respuesta.texto.pid=pid;
                        msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);


				} // Fin else

			}//Fin Formulario eliusu

/*************************************************************************
				Buscar Personas 
*************************************************************************/

                        if (strcmp(formulario, "bususu")==0){

                                printf("   --------------------   \n   Te encontrare gente! \n   --------------------\n\n");

                                char rut[9];
                             
                                //Limpiamos los Strings

                                memset (rut, 0, sizeof rut);
                                
                                //Recibimos los datos desde el .c

                                printf("Recibi: %s\n",mensaje.texto.datos);
                                sscanf(mensaje.texto.datos, "%6c%8c", formulario, rut);
                             
                             //Guardamos la variable en la estructura arr de los char
								
								sprintf(SQL_rut.arr,"%s", rut);
								SQL_rut.len=strlen(SQL_rut.arr);
								
								printf("El Rut de la Persona es: %s\n", SQL_rut.arr);
								
				// Verificamos si el rut existe.
				
								{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from USUARIO where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)9,(long)1,sizeof(struct varchar_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 466 "demonio.pgc"

				
                                if( SQL_count != 0) {
                                    //Obtenemos datos del cliente que buscamos 
                                        
								// buscamos al super usuario de la temuer
								{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select nombre , apellido , mail , clave from USUARIO where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)9,(long)1,sizeof(struct varchar_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_varchar,&(SQL_nombre_usuario),(long)21,(long)1,sizeof(struct varchar_4), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_apellido),(long)21,(long)1,sizeof(struct varchar_5), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, 
	ECPGt_varchar,&(SQL_mail),(long)51,(long)1,sizeof(struct varchar_6), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 472 "demonio.pgc"
 
								{ ECPGtrans(__LINE__, NULL, "commit");}
#line 473 "demonio.pgc"

					
						        printf("Nombre es: %s\n", SQL_nombre_usuario.arr);
                                printf("Apellido es: %s\n", SQL_apellido.arr);
                                printf("Rut es: %s\n", SQL_rut.arr);
                                printf("Mail es: %s\n", SQL_mail.arr);
                                
		
									
                              // mandamos la informacion al C. 									
									
									memset( &respuesta, 0, sizeof respuesta);
                                        sprintf(respuesta.texto.datos, "%2s%20s%20s%50s", "02",SQL_nombre_usuario.arr, SQL_apellido.arr, SQL_mail.arr);
										respuesta.mtype = pid_destino;
                                        respuesta.texto.pid = pid;
                                        msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);										
									
									//sprintf(respuesta.texto.datos,"%2s%20s%10d%10d%9d","01",SQL_nombrepro.arr,SQL_precio,SQL_cantidad,SQL_rutv);
									
										printf("\n  Muestrame la infor ! \n\n");
					
					} else {
						
						printf("\n  Usuario  no esta registrado \n\n");

						memset(&respuesta,0,sizeof respuesta);
                        sprintf(respuesta.texto.datos, "%s", "01");
						respuesta.mtype=pid_destino;
                        respuesta.texto.pid=pid;
                        msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);


				} // Fin else

			}//Fin Formulario bususu
			
/*************************************************************************
                       Modificar usuario
*************************************************************************/

                        if (strcmp(formulario, "modusu")==0){

                                printf("   --------------------   \n   Modificar Usuario \n   --------------------\n\n");

                                char nombre[21];
                                char apellido[21];
                                char rut[9];
                                char mail[51];
                                char clave[21];

                                //Limpiamos los Strings
                                memset (nombre, 0, sizeof nombre);
                                memset (apellido, 0, sizeof apellido);
                                memset (rut, 0, sizeof rut);
                                memset (mail, 0, sizeof mail);
                                memset (clave, 0, sizeof clave);
                                                     

                                //Recibimos los datos desde el .c

                                printf("Recibi: %s\n",mensaje.texto.datos);
                                sscanf(mensaje.texto.datos, "%6c%8c%20c%20c%50c%20c", formulario, rut, nombre, apellido, mail, clave);
                             
                             //Guardamos la variable en la estructura arr de los char
								sprintf(SQL_rut.arr,"%s", rut);
								SQL_rut.len=strlen(SQL_rut.arr);
								
								sprintf(SQL_nombre_usuario.arr,"%s", nombre);
								SQL_nombre_usuario.len=strlen(SQL_nombre_usuario.arr);
								
								sprintf(SQL_apellido.arr,"%s", apellido);
								SQL_apellido.len=strlen(SQL_apellido.arr);
								
								sprintf(SQL_mail.arr,"%s", mail);
								SQL_mail.len=strlen(SQL_mail.arr);
								
								sprintf(SQL_clave.arr,"%s", clave);
								SQL_clave.len=strlen(SQL_clave.arr);


                                // Verificamos si el usuario ya esta registrado
                                { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "select count ( * ) from usuario where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)9,(long)1,sizeof(struct varchar_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, 
	ECPGt_int,&(SQL_count),(long)1,(long)1,sizeof(int), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);}
#line 554 "demonio.pgc"


                                if( SQL_count != 0) {

                                        { ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "update usuario set nombre = SQL_nombre_usuario , apellido = SQL_apellido , mail = SQL_mail , clave = SQL_clave where rut = $1 ", 
	ECPGt_varchar,&(SQL_rut),(long)9,(long)1,sizeof(struct varchar_7), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);}
#line 558 "demonio.pgc"

                                        { ECPGtrans(__LINE__, NULL, "commit");}
#line 559 "demonio.pgc"


                                        // Revisar en caso de error en la consulta
                                        if(sqlca.sqlcode != 0) {

                                                printf("\nERROR en la Actualizacion SQL\n\n");

                                                memset(&respuesta,0,sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "04");
                                                respuesta.mtype=pid_destino;
                                                respuesta.texto.pid=pid;
                                                msgsnd(qid,&respuesta,strlen(respuesta.texto.datos)+4,0);

                                        } else {

                                                printf("\n Actualizado con exito\n\n");

                                                memset( &respuesta, 0, sizeof respuesta);
                                                sprintf(respuesta.texto.datos, "%s", "03");
                                                respuesta.mtype = pid_destino;
                                                respuesta.texto.pid = pid;
                                                msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);

                                        }                                                                                                                                                            

                                }else{

                                        printf("No existe el Usuario\n");

                                        memset( &respuesta, 0, sizeof respuesta);
                                        sprintf(respuesta.texto.datos, "%2s", "01");
                                        respuesta.mtype = pid_destino;
                                        respuesta.texto.pid = pid;
                                        msgsnd(qid, &respuesta, strlen(respuesta.texto.datos)+4,0);

                                } // Fin else

                        }//Fin Formulario modusu
			
			
			} // estos parentesis no se mueven al agregar  formulario (  U CANT TOUCH THIS (8)! )
}

}



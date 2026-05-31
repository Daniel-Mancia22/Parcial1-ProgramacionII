# Parcial I - Programación II 

## Descripción
Este proyecto corresponde a la sección práctica (70%) del **Primer Parcial de Programación II**. Consiste en una aplicación de consola desarrollada en **C++** utilizando el IDE **Code::Blocks**, diseñada para la gestión automatizada de clientes, préstamos y control de pagos mediante un sistema orientado a objetos.

## Funcionalidades Principales

### **Gestión de Clientes (Opción 1 y 4)**
- **Registro Individual:** Captura de datos uno a uno (Código, Nombre y Apellido).
- **Estructura Orientada a Objetos:** Instanciación de objetos de la clase `Cliente` y almacenamiento en un arreglo/vector dinámico.
- **Control de Desbordamiento:** Validación automática del límite máximo del vector, notificando al usuario mediante un mensaje de "Lista Llena" cuando se alcanza la dimensión máxima definida.
- **Visualización:** Listado completo y estructurado de todos los clientes registrados en el sistema.

### **Control de Préstamos (Opción 2, 5 y 6)**
- **Asignación Vinculada:** Solicitud del código del cliente para realizar una búsqueda previa. Solo si el cliente existe, se permite capturar los datos del préstamo y generar el objeto de tipo `Prestamo`.
- **Validación de Existencia:** Si el cliente no se encuentra en el sistema, se muestra un mensaje de error explícito y se deniega la captura del préstamo, regresando de inmediato al menú principal.
- **Monitoreo Global y Detallado:** Opciones dedicadas para listar de forma general todos los préstamos vigentes o consultar los detalles específicos de un préstamo en particular mediante su identificador.

### **Registro de Pagos (Opción 3)**
- **Búsqueda por Código:** Localización del préstamo objetivo mediante su código único.
- **Amortización:** Captura detallada de la fecha y el monto del pago para registrarlo directamente dentro del historial de la entidad del préstamo correspondiente.

---

## Tecnologías y Herramientas Utilizadas

### Entorno y Lenguaje
- **C++** - Lenguaje base enfocado en Programación Orientada a Objetos (POO).
- **Code::Blocks** - Entorno de Desarrollo Integrado (IDE) utilizado para la escritura, compilación y depuración del código fuente (`.cbp`, `.depend`, `.layout`).
- **GNU GCC Compiler** - Compilador estándar empleado para la generación del ejecutable.

### Arquitectura de Software
- **Modularidad (Archivos de Cabecera):** Separación de responsabilidades mediante clases independientes estructuradas en archivos `.h`:
  - `Cliente.h`: Definición de atributos y métodos de la entidad cliente.
  - `Prestamo.h`: Estructura para el manejo de créditos asignados.
  - `Pago.h`: Control individual de las transacciones y abonos de los clientes.
  - `Fecha.h`: Clase utilitaria para la gestión estandarizada de tiempos y fechas de transacciones.
- **Flujo de Consola Principal (`main.cpp`):** Controlador centralizado con un ciclo interactivo (`do-while`) y evaluación de opciones mediante estructuras condicionales (`switch-case`).

---

## Flujo de la Aplicación

### Ciclo del Menú de Opciones
Al ejecutar el programa, se despliega un menú interactivo con las siguientes opciones numeradas:
1. **Agregar clientes a la lista** → Captura de datos de un cliente y retorno automático al menú.
2. **Agregar préstamo a la lista** → Verificación del cliente y creación del crédito.
3. **Hacer pagos de préstamos** → Aplicación de abonos financieros a un préstamo existente.
4. **Mostrar lista de clientes** → Impresión en pantalla de todos los registros de clientes.
5. **Mostrar lista de prestamos** → Despliegue general de los créditos otorgados.
6. **Mostrar detalles del préstamo** → Consulta específica de un préstamo y sus movimientos.
7. **Salir** → Finalización segura de la ejecución del software.

---

## Validaciones y Reglas de Negocio

- **Verificación Estricta de Clientes:** No se puede otorgar un préstamo a un código de cliente inexistente.
- **Dimensión Controlada:** El tamaño de los vectores/arreglos está definido bajo un límite estricto para evitar accesos inválidos a la memoria física (Buffer Overflow).
- **Flujo Fluido de Entrada/Salida:** Limpieza de búfer de entrada en consola para evitar saltos de línea erróneos durante la captura secuencial de cadenas de texto (strings).

---

## Desarrollador
- [Daniel Mancia](https://github.com/Daniel-Mancia22) - DevMadCode

---

## Notas del Proyecto
- **Propósito Académico:** Desarrollado y defendido como solución práctica correspondiente al 70% de la nota del **Primer Parcial** de la materia **Programación II**.
- **Enfoque de Modularidad:** Implementación limpia de encapsulamiento y punteros/arreglos utilizando buenas prácticas de programación en C++.

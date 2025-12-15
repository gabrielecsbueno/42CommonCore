*Este proyecto ha sido creado como parte del currículo de 42 por <gabde-so>[gabde-so]().*

## **Descripción**

Este proyecto consiste en la creación de una máquina virtual (VM), un ambiente virtual que funciona como un ordenador físico completo (con CPU, memoria, disco y red propios) que ejecuta su propio sistema operativo, todo ello dentro de otro ordenador físico (el host).

La VM está aislada del sistema host, lo que permite a los usuarios realizar tareas seguras, como probar y desarrollar aplicaciones o utilizar distintos sistemas operativos, al paso que optimizan el hardware físico.

En este proyecto se utilizó el software VirtualBox, un software gratuito y de código abierto de Oracle, para crear una VM del sistema operativo Debian.

El sistema Debian utilizado en este proyecto utiliza el kernel Linux.

El kernel es el programa más fundamental del ordenador, se encuentra en el núcleo del sistema operativo y realiza todas las operaciones más básicas, lo que le permite ejecutar otros programas.

Toda la informacion especifica del proyecto esta en el [subject](https://cdn.intra.42.fr/pdf/pdf/189113/en.subject.pdf) de 42.

## **Instrucciones**

Para la evaluación, este repositorio contiene el archivo `Signature.txt`, que consiste en la firma de la máquina virtual creada.
Compruébelo y compárelo en el archivo:

```bash
Born2beRoot/
 └── Born2beRoot.vdi
```

Utilizando el comando:

```bash
$ sha1sum Born2beRoot.vdi #Na pasta do projeto Born2beRoot
$ cat Signature.txt #Arquivo do repositorio
```

## **Recursos**

[Sistema operacional Debian](https://www.debian.org/distrib/)

[Informacion sobre firewalls](https://www.rootzilopochtli.com/introduccion-a-la-seguridad-y-el-firewall)

[Informacion sobre LSMs](https://tuxcare.com/blog/selinux-vs-apparmor/)

[info sobre 42Barcelona](https://www.42barcelona.com/es/)


## **Descripción del proyecto**

### **1. Debian vs Rocky Linux**

Al elegir un sistema operativo para nuestro servidor, se consideraron algunos puntos importantes.

Al ser el primer proyecto relacionado con la administración de sistemas, Debian fue el sistema más ventajoso para la creación de la máquina virtual.

Aunque Rocky es un sistema fiable con ventajas como la estabilidad y la seguridad robusta (SELinux), tiene una curva de aprendizaje más difícil para quienes no están acostumbrados al ecosistema Linux para servidores.

Algunas de las ventajas que se tuvieron en cuenta al elegir Debian fueron:

◦ Enfoque en la seguridad y la privacidad: la distribución Linux no supervisa las actividades de los usuarios, lo que garantiza un entorno privado.

◦ Resistencia al malware y los virus: el control de permisos (root) y el modelo de seguridad de Linux dificultan la acción de programas maliciosos, impidiendo daños sin la autorización explícita del usuario;

◦ Amplia disponibilidad de software: ofrece una extensa biblioteca de paquetes de software compatibles, que abarca desde herramientas de productividad hasta entornos de desarrollo para diversos lenguajes de programación;

### **2. AppArmor vs SELinux**

AppArmor y SELinux son módulos de seguridad de Linux (LSM) que sirven para implementar un control de acceso obligatorio al servidor.

Se diferencian en cómo aplican las políticas y en su complejidad de gestión.

AppArmor ofrece un enfoque más sencillo y basado en rutas para la seguridad, asignando reglas a rutas de archivos, mientras que SELinux proporciona un control basado en etiquetas para una mayor seguridad, asignando reglas a contextos de seguridad y etiquetas de objetos.

AppArmor tiene una curva de aprendizaje más fácil para los nuevos usuarios, además de una menor sobrecarga y un procesamiento de reglas más sencillo, ideal para sistemas ligeros.

Por su parte, SELinux añade más complejidad y procesamiento debido a su sistema de etiquetado, pero está optimizado para el rendimiento en sistemas corporativos.

### **3. UFW vs firewalld**

Ufw (estándar en Debian y Ubuntu) y Firewalld son herramientas para configurar el firewall del servidor.

Un firewall actúa como un portero o guardián de la red. Es un sistema de seguridad que supervisa y controla el tráfico de red entrante y salida basado en un conjunto de reglas de seguridad predefinidas.
Su objetivo principal es establecer una barrera entre una red confiable (como su sistema interno o red) y redes no confiables (como Internet).

Para configurarlo, se puede utilizar Firewalld, que es un gestor dinámico que utiliza el concepto de zonas para organizar las reglas de red. Es el estándar en distribuciones como Rocky Linux, CentOS y Fedora.

Sin embargo, en este servidor se utilizó UFW, que es un gestor más sencillo y común en Debian. Tiene una interfaz simplificada, fácil de configurar, diseñada para facilitar la configuración de los firewalls.

### **4. VirtualBox vs UTM**

VirtualBox y UTM son programas que se usan para crear máquinas virtuales (VM).

VirtualBox hace una virtualización directa del hardware y ofrece un mejor rendimiento, pero la máquina virtual tiene que usar la misma arquitectura que el procesador físico (x86_64).

UTM, basado en QEMU (Quick Emulator), permite tanto la virtualización como la emulación, siendo más útil en Macs, donde es necesario emular la arquitectura x86.

En este proyecto, se eligió VirtualBox porque se utiliza en un ordenador con procesador Intel, lo que permite la virtualización nativa, un mejor rendimiento y una mayor estabilidad.

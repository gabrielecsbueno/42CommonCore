*Este proyecto ha sido creado como parte del currículo de 42 por <gabde-so>[gabde-so]().*

## **Descripción**

Este projeto é a criacao de uma máquina virtual (VM), um ambiente virtual que funciona como um computador fisico completo (com CPU, memória, disco e rede própria) executando o seu próprio sistema operacional, tudo isso rodando dentro de outro computador físico (o host).

A VM é isolada do sistema host, isso permite que os usuários realizem tarefas seguras, como testar e desenvolver aplicativos ou usar diferentes sistemas operacionais, enquanto otimizam o hardware físico.

Nesse projeto foi utilizado o software VirtualBox, um software gratuito e de código aberto da Oracle, para criar uma VM do sistema operacional Debian.

Os sistema Debian utilizado nesse projeto usa o kernel Linux.

Kernel é o programa mais fundamental no computador, esta no nucleo do sistema operacional, e faz todas as operações mais básicas, permitindo que você execute outros programas.

Toda la informacion especifica del proyecto esta en el [subject](https://cdn.intra.42.fr/pdf/pdf/189113/en.subject.pdf) de 42.

## **Instrucciones**

Para a avaliacao, nesse repositorio possui o arquivo `Signature.txt`, que consiste na assinatura da maquina virtual criada.
Verifique e compare no arquivo :

```bash
Born2beRoot/
 └── Born2beRoot.vdi
```

Utilizando o comando:

```bash
$ sha1sum Born2beRoot.vdi #Na pasta do projeto Born2beRoot
$ cat Signature.txt #Arquivo do repositorio
```

## **Project description**

### **1. Debian vs Rocky Linux **

Ao escolher um sistema operacional ao nosso servidor foi considerado alguns pontos importantes.

Por ser o primeiro projeto relacionado a administracao de sistemas, o Debian foi o sistema que mais vantajoso para a criacao da VM.

Mesmo o Rocky sendo um sitema confiavel com vantagens como estabilidade e segurança robusta (SELinux), ele tem uma curva de aprendizado mais dificil para quem não está acostumado com o ecossistema Linux para servidores.

Algumas vantagens consideradas ao escolher o Debian foi:

Foco em segurança e privacidade: a distribuição Linux não monitora as atividades dos usuários, isso garante um ambiente privado;

Resistência a malwares e vírus: o controle de permissões (root) e o modelo de segurança do Linux dificulta a ação de programas malicioso, impedindo danos sem a autorização explícita do usuário;

Ampla disponibilidade de software: oferece uma extensa biblioteca de pacotes de softwares compatíveis, abrangendo desde ferramentas de produtividade até ambientes de desenvolvimento para diversas linguagens de programação;

### **2. AppArmor vs SELinux**

AppArmor e o SELinux são Módulos de Segurança Linux (LSMs), que servem para implementar um Controle de Acesso Obrigatório ao servidor.

Eles diferem em como aplicam políticas e a complexidade ao gerenciar.

O AppArmor oferece uma abordagem mais simples e baseada em caminho para a segurança, atribuindo regras a caminhos de arquivo, enquanto o SELinux fornece um controle baseado em rótulos para maior segurança, atribuindo regras a contextos de segurança e rótulos de objetos.

O AppArmor tem uma curva de aprendizado mais facil para novos usuarios, alem de uma sobrecarga mais baixa e processamento de regras mais simples, ideal para sistemas leves.

Ja o SELinux adiciona mais complexidade e processamento devido ao seu sistema de rotulagem, mas é otimizado para desempenho em sistemas corporativos.

### **3. ◦ UFW vs firewalld**

Ufw (padrão no Debian e Ubuntu) e Firewalld sao ferramentas para configurar o firewall do servidor.

Um firewall atua como um porteiro ou guarda de rede. É um sistema de segurança que monitora e controla o tráfego de rede de entrada e saída com base em um conjunto de regras de segurança predefinidas.
Seu principal objetivo é estabelecer uma barreira entre uma rede confiável (como seu sistema interno ou rede) e redes não confiáveis (como a Internet).

Para configurar é possivel utilizar o Firewalld, que é um gerenciador dinâmico que utiliza o conceito de zonas para organizar as regras de rede. É o padrão em distribuições como Rocky Linux, CentOS e Fedora.

No entento, nesse servidor foi utilizado o UFW, que é um gerenciador mais simples e comum em Debian. Tem uma interface simplificada, facil de configurar, projetada para facilitar a configuração de firewalls.

### **4. ◦ VirtualBox vs UTM**

VirtualBox e UTM são softwares usadas para criar máquinas virtuais (VMs).

O VirtualBox realiza virtualização direta do hardware e oferece melhor desempenho, no entanto a máquina virtual precisa utilizar a mesma arquitetura do processador físico (x86_64).

O UTM, baseado no QEMU (Quick Emulator), permite tanto virtualização quanto emulação, sendo mais útil em Macs, onde é necessário emular a arquitetura x86.

Neste projeto, foi escolhido o VirtualBox por estar sendo utilizado em um computador com processador Intel, permitindo virtualização nativa, melhor performance e maior estabilidade.

## **Recursos**

[Sistema operacional Debian](https://www.debian.org/distrib/)

[Informacion sobre ... ](https://www.ibm.com/docs/es/i/7.5.0?topic=functions-printf-print-formatted-characters)

[info sobre 42Barcelona](https://www.42barcelona.com/es/)

From kalilinux/kali-linux-docker

#add specific tools I need
RUN apt-get update -y && apt-get upgrade -y && apt-get dist-upgrade -y 
RUN apt-get install ncat -y && apt-get update && apt-get install metasploit-framework -y
RUN apt-get install hydra -y
RUN git clone https://github.com/longld/peda.git ~/peda
RUN echo "source ~/peda/peda.py" >> ~/.gdbinit
RUN apt-get install sqlmap -y

#installing my github stuff and commands
RUN mkdir home/github
RUN git clone https://github.com/ElQwerto110100100/hacking-scripts.git home/github
RUN ENV PATH "$PATH:/home/github/custom-commands"
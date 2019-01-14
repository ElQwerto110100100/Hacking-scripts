From kalilinux/kali-linux-docker

#add specific tools I need
RUN apt-get install ncat -y && apt-get update && apt-get install metasploit-framework -y
RUN apt-get install hydra -y
RUN git clone https://github.com/longld/peda.git ~/peda
RUN echo "source ~/peda/peda.py" >> ~/.gdbinit

#install word list for bruteforce cracking
RUN mkdir usr/share/wordlists
RUN wget http://downloads.skullsecurity.org/passwords/rockyou.txt.bz2 -O usr/share/wordlists
RUN tar xvjf -C usr/share/wordlists/rockyou.txt.bz2

#installing my github stuff and commands
RUN mkdir home/github
RUN git clone https://github.com/ElQwerto110100100/hacking-scripts.git home/github
RUN ENV PATH="/home/github/hacking-scripts/custom-commands:${PATH}"

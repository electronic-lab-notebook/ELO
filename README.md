# ELO
***ELO is not activly mainteines any more. Feel free to fork!***

ELO is an **E**lectronic **L**ab j**O**urnal based on git. Instead of heaving a web interface with a server, ELO is based on lokal installations of the desktop software. Because of the local installation interactions with local files ist possible. Files can be stores inside the lab journal (which is an git repository) or outside (means external files). Bothe can be linked into the experiment description files. To maintain valid links for external files, shortcuts can be defined. 

ELO saves the experiment description files as valid HTML with metadata as comment in the first line of the document. So all Files can be displayd outside ELo with a web browser. 

The desktop software pulls (or clones) the lab journal as git repository from any gitolite server, configured to serve ELO. Therefore, at least two copies of all data are avaible to prevent data loss at any time.  Additionally, git keeps track of all changes. 

## Server needed!
Yout have to set up an gitolite Server with an repository wich is called *ELO-admin* and *ELO-Templates*.

## Requirements
* Qt6
* libgit2
* libssh (only for ELO-admin)
* libssh2
* openssl

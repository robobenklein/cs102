# Hakd

The security on the cs102 lab and debug server (and I presume the other lab-testing servers) need to be fixed SEVERELY.

There are GAPING HOLES in the security of the web application that allows students to test their code.

The most prominent and worst vulnerability comes from the fact that the CodeAssessor System does not chroot or ns-separate the code that students upload.  
This means that any code a student can upload can be executed with full privileges of the user for the service that runs the code.

For example, I am able to cout the /etc/passwd file from the system using a simple c++ snippet. I have included that /etc/passwd file in hopes that this will encourage the devs to fix their security.

section .data
    ; Déclaration des variables
    a db 5          ; Premier opérande
    b db 3          ; Deuxième opérande
    result db 0     ; Résultat
    msg db 'Resultat: ', 0  ; Message à afficher
    msg_len equ $ - msg      ; Longueur du message

section .text
    global _start

_start:
    ; Addition
    mov al, [a]     ; Charger a dans AL
    add al, [b]     ; Ajouter b à AL
    mov [result], al ; Stocker le résultat

    ; Afficher le message
    mov rax, 1      ; Appel système pour write
    mov rdi, 1      ; Descripteur de fichier pour stdout
    mov rsi, msg    ; Adresse du message
    mov rdx, msg_len; Longueur du message
    syscall

    ; Afficher le résultat
    mov rax, 1      ; Appel système pour write
    mov rdi, 1      ; Descripteur de fichier pour stdout
    mov rsi, result ; Adresse du résultat
    mov rdx, 1      ; Longueur du résultat (1 octet)
    syscall

    ; Terminer le programme
    mov eax, 60     ; Appel système pour exit
    xor edi, edi    ; Code de sortie 0
    syscall
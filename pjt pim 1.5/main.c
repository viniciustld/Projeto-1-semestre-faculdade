#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#define tamanho 200

int opcao;
int logop;

void cadastroAtl(){
	


	FILE *fp, *fo;
	fp = fopen("cadastroAtl.txt", "a"); /* Apos termino de teste mudar o ("w") para ("a") */
	if (fp == NULL){

		puts("arquivo corrompido");
		return;
	}
	fo = fopen("cadastroHpd.txt", "a");
	if (fo == NULL){

		puts("arquivo corrompido");
		return;
	}

char nome [tamanho], modalidade[tamanho], pais[tamanho], hospedagem[tamanho], eolimpic[tamanho];
int idade, op;
time_t t;
time(&t);

fprintf(fp, "%s %s", "Cadastro Efetuado em :", ctime(&t));
fprintf(fp, "%-30s %-30s %-30s %-30s\n", "Nome", "Modalidade", "Pais", "Idade");
fprintf(fo, "%s %s", "Cadastro Efetuado em :", ctime(&t));
fprintf(fo, "%-30s %-30s\n", "Equipe Olimpica", "Hospedagem");


    do{
    	inicio:
    	puts("##\tDigite as informacoes do atleta solicitado\t##");
        puts("Digite o Nome:\n");
        gets(nome);
        fflush(stdin);
        puts("\nDigite qual Modalidade:\n");
        gets(modalidade);
        fflush(stdin);
        puts("\nDigite o Pais:\n");
        gets(pais);
        fflush(stdin);
        puts("\nDigite a Idade:\n");
        scanf("%d", &idade);
        fflush(stdin);
        puts("\nDigite o Local de Hospedagem do Atleta:\n");
        gets(hospedagem);
        fflush(stdin);
        puts("\nDigite a Equipe Olimpica:\n");
        gets(eolimpic);
        fflush(stdin);
        puts("\n##\tDados Registrados\t##\n");
        fprintf(fp, "%-30s %-30s %-30s %-30d \n", nome, modalidade, pais, idade);
        fprintf(fo, "%-30s %-30s\n", eolimpic, hospedagem);


        puts("Cadastro efetuado,\nDigite '1' para continuar ou '0' para sair: ");
        scanf("%d", &op);
        system("cls");
        fflush(stdin);

        }
		while(op==1);

	fclose(fp);
	fclose(fo);

}

void pesquisaAtleta(){
	
	FILE *abritxt, *abritxt2;
	char lista[1000];
	char lista2[1000];
	abritxt = fopen("cadastroAtl.txt", "r");
	abritxt2 = fopen("cadastroHpd.txt", "r");
	
	int i;
	
	for (i=0; i<10; i++){
		
		printf("%s\n", fgets(lista, 1000, abritxt));
}
	for (i=0; i<10; i++){
		
		printf("%s\n", fgets(lista, 1000, abritxt2));
	}
	fclose(abritxt);
	system("pause");
	}

void medalhas(){
	
	int mop, mpp, mbp, moa, mpa, mba;
	int op, lp;
	char pais[30], atleta[30];
	time_t t;
	time(&t);
	
	FILE *md;
	md = fopen("medalhas.txt", "a");
	if(!md){
		
		puts("arquivo inexistente");
		return;
	}

	fprintf(md, "%s %s", "Cadastro Efetuado em :", ctime(&t));
	fprintf(md, "%-30s %-30s %-30s %-30s\n", "Pais/Atleta", "Ouro", "Prata", "Bronze");	
	
	puts("insira (1) para pais ou (2) para atleta");
	scanf("%d", &op);
	getchar();
	
	
	do{
		
		switch (op){
		
			case 1:	
			
				puts("Digite o Pais a contabilizar medalhas:");
				scanf("%s", &pais);
				getchar();
				printf("Quantas medalhas de ouro?\n");
				scanf("%d", &mop);
				getchar();
				printf("Quantas medalhas de prata?\n");
				scanf("%d", &mpp);
				getchar();
				printf("Quantas medalhas de bronze?\n");
				scanf("%d", &mbp);
				getchar();
				fprintf(md, "%-30s %-30d %-30d %-30d\n", pais, mop, mpp, mbp);				
        		puts("Medalhas Contadas \nDigite '1' para continuar ou '0' para sair: ");
        		scanf("%d", &lp);
       			system("cls");
        		getchar();
        		break;
        		
        	case 2:

				puts("qual atleta a se contabilizar medalhas?");
				scanf("%s", &atleta);
				getchar();
				printf("Quantas medalhas de ouro?\n");
				scanf("%d", &moa);
				getchar();
				printf("Quantas medalhas de prata?\n");
				scanf("%d", &mpa);
				getchar();
				printf("Quantas medalhas de bronze?\n");
				scanf("%d", &mba);
				getchar();
			//	fprintf(md, "%-30s %-30d %-30d %-30d\n", atleta, moa, mpa, mba);
				puts("Medalhas Contadas \nDigite '1' para continuar ou '0' para sair: ");
        		scanf("%d", &lp);
       			system("cls");
        		getchar();
        		
		} // fecha switch case
		} // fecha do loop
		
		while(lp==1);
		fclose(md);
	}

void mostramed(){
	
	FILE *mm;
	char lista[1000];
	mm = fopen("medalhas.txt", "r");
	
	int i;
	
	for (i=0; i<10; i++){
		
		printf("%s\n", fgets(lista, 1000, mm));
}
	fclose(mm);
	system("pause");
	}

void telalogin(){

    char login[15] = "admin";
    char login1[15];
    char senha[15] = "admin";
    char senha1[15];

    puts("\t###########################");
    puts("\t Programa de Gerenciamento");
    puts("\t     das olimpiadas");
	puts("\t Digite o Login e Senha: ");
    scanf("\t%s%s", &login1, &senha1);
    fflush(stdin);
    system("cls");

    if (strcmp(login, login1) == 0 && strcmp(senha, senha1) == 0){
		puts("\tLOGADO COMO ADM!");
		logop = 1;
		}

    else{
		puts("LOGADO COMO USUARIO");
		logop = 0;
		}

	}

void mostrarmenu(){

	if (logop == 1){

	puts("");
    puts("\t**SEJA BEM VINDO AO SISTEMA**");
    puts("\t****DE ATLETAS OLIMPICOS****");
	puts("");
    puts("\t0) - RELOGAR NO SISTEMA");
    puts("\t1) - SAIR DO SISTEMA");
    puts("\t2) - CADASTRAR ATLETAS");
    puts("\t3) - LISTA DE ATLETAS");
    puts("\t4) - CRONOGRAMA DE EVENTOS");
    puts("\t5) - ORIENTACOES");
    puts("\t6) - CONTABILIZACAO DE MEDALHAS");
    puts("\t7) - LISTA DE MEDALHAS\n");
    puts("\tDIGITE A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");

}

	else if (logop == 0){

	puts("");
    puts("\t**SEJA BEM VINDO AO SISTEMA**");
    puts("\t****DE ATLETAS OLIMPICOS****");
	puts("");
    puts("\t0) - RELOGAR NO SISTEMA");
	puts("\t1) - SAIR DO SISTEMA");
	puts("\t3) - LISTA DE ATLETAS");
	puts("\t4) - CRONOGRAMA DE EVENTOS");
	puts("\t5) - ORIENTACOES");
	puts("\t7) - LISTA DE MEDALHAS\n");
	puts("\tDIGITE A OPÇÃO DESEJADA: ");
    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");

	}

}

int main(){
	
	system("color 71");


    setlocale(LC_ALL, "PORTUGUESE");

	telalogin:
    telalogin();

    mostrarmenu:
    mostrarmenu();

        switch (opcao)

        {
            case 2 : // Gravar atletas

                cadastroAtl();
                system("cls");
				goto mostrarmenu;

            case 3 : // lista atl e hpd

                pesquisaAtleta();
                system("cls");
				goto mostrarmenu;

            case 1: // sai do programa

                puts("Fim Do Programa");
                system("pause");
				break;

			case 0: // relogar sistema

				system("cls");
				puts("Deslogado Com Susesso");
				goto telalogin;

			case 4: // cronograma

				puts("");
				puts("Devido aos Acontecimentos Passados a Capacidade dos Eventos Presenciais foi Reduzida \n");
				puts("Cronograma de Eventos dos Jogos da XXXIII Olimpíada Paris 2024\n");
				printf("%-30s %-30s %-30s %-30s\n", "Evento", "Local", "Data", "Observacoes");
				printf("%-30s %-30s %-30s %-30s", "Cerimonia de Abertura", "Orla Do Rio Sena", "26 de Julho de 2024", "Capacidade (9.000 espectadores)\n");
				printf("%-30s %-30s %-30s %-30s", "Futebol", "Parc des Princes", "27 de Julho de 2024", "Capacidade (45.500 espectadores)\n");
				printf("%-30s %-30s %-30s %-30s", "Tenis", "Stade Roland Garros", "28 de julho de 2024", "Capacidade (8.500 espectadores)\n\n");
				system("pause");


                puts("Tecle 'Enter' para voltar ao Menu de Opcoes");
                system("cls");
                goto mostrarmenu;

            case 5: // guia do atleta com informacoes uteis

            	/*puts("O guia a Seguir contem as informacoes necessarias para todos os atletas e suas respectivas equipes do centro olimpico:");*/
            	puts("O guia a seguir e destinado as equipes do centro olimpico, medicos e atletas:\n");
            	puts("Cabe a equipe de centro olimpico:\n");
            	puts("\t*Fornecer os dados para inscriçao dos atletas");
            	puts("\t*Organizar treinamentos e agenda da equipe");
            	puts("\t*Fornecer e solicitar equipamentos necessarios para atividades\n");
            	system("pause");
            	system("cls");
            	goto mostrarmenu;

            case 6: // parte de medalhas

            	medalhas();
            	system("cls");
            	goto mostrarmenu;
            	
            case 7: // lista de atl
            
            	mostramed();
            	system("cls");
            	goto mostrarmenu;

            default :

                puts("Opção Invalida!");
				break;
        }
return(0);
}

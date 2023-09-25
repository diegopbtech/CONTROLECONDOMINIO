#include <iostream>
#include <fstream>
#include <locale.h>
#include <stdlib.h>
using namespace std;

struct CadastroCondominio {
    string nome;
    string endereco;
    string cep;
    string bairro;
    string cidade;
    string estado;
    string mensagens[1000];
    string telefone;
    int nummoradores;
    string moradores[10000];
    string despesas[1000];
    float gastosdespesa[1000];
};

struct CadastroAdmin{
    string nome;
    string cpf;
    string rg;
    string contato;
    string estadocivil;
    int idade;
    string email;
    string senha;
};

struct CadastroMorador{
    string nome;
    string cpf;
    string rg;
    string estadocivil;
    int numero;
    string senha;
};

struct CadastroFuncionario{
    string nome;
    string cpf;
    string funcao;
    float salario;
};

string DesignCadastroCondominio();
string DesignMenu();
string menumorador();
string menuadmin();
string designcondominio(string var1, int var2, int var3, string var4, string var5, string var6, string var7);

int main()
{
    setlocale (LC_ALL, "Portuguese");
    int opcao;
    CadastroAdmin admin;
    ifstream nomeadminE;
    nomeadminE.open("Nomedoadmin.txt");
    getline (nomeadminE, admin.nome);
    nomeadminE.close();
    ifstream cpfadminE;
    cpfadminE.open ("cpfadmin.txt");
    cpfadminE >> admin.cpf;
    cpfadminE.close();
    ifstream rgadminE;
    rgadminE.open ("rgadmin.txt");
    rgadminE >> admin.rg;
    rgadminE.close();
    ifstream estadociviladminE;
    estadociviladminE.open ("estadociviladmin.txt");
    estadociviladminE >> admin.estadocivil;
    estadociviladminE.close();
    ifstream anoadminE;
    anoadminE.open ("idadeadmin.txt");
    anoadminE >> admin.idade;
    anoadminE.close();
    int contadmintel;
    ifstream contAE;
    contAE.open ("ContAdminTel.txt");
    contAE >> contadmintel;
    contAE.close();
    int contmorador;
    ifstream contME;
    contME.open("ContMorador.txt");
    contME >> contmorador;
    contME.close();
    fstream contatoadmin;
    contatoadmin.open ("contatoadmin.txt", ios::in);
        for(int i=0;i<contadmintel;i++){
            contatoadmin >> admin.contato[i];
        }
    contatoadmin.close();
    ifstream emailadminE;
    emailadminE.open ("EmaildoAdmin.txt");
    emailadminE >> admin.email;
    emailadminE.close();
    ifstream senhaadminE;
    senhaadminE.open("SenhadoAdmin.txt");
    senhaadminE >> admin.senha;
    senhaadminE.close();

    CadastroCondominio condominio;
    int despesasgerais;
    ifstream despesasgeraisE;
    despesasgeraisE.open("Despesasgerais.txt");
    despesasgeraisE >> despesasgerais;
    despesasgeraisE.close();
    float gastosgeral;
    ifstream gastosE;
    gastosE.open("Gastosgerais.txt");
    gastosE >> gastosgeral;
    gastosE.close();
    int salariofuncionarios;
    ifstream salariofuncE;
    salariofuncE.open("despesascomfuncionarios.txt");
    salariofuncE >> salariofuncionarios;
    salariofuncE.close();
    int numerodespesas;
    ifstream ndespesasE;
    ndespesasE.open("Númerodedespesas.txt");
    ndespesasE >> numerodespesas;
    ndespesasE.close();
    fstream despesas;
    despesas.open("Despesasdocondominio.txt", ios::in);
    for (int o=0;o<=numerodespesas;o++){
    getline (despesas, condominio.despesas[o]);
    }
    despesas.close();
    fstream gastodespesa;
    gastodespesa.open("Gastosdasdespesas.txt", ios::in);
    for(int p=0;p<=numerodespesas;p++){
        gastodespesa >> condominio.gastosdespesa[p];
    }
    gastodespesa.close();
    int nmensagens;
    ifstream numeromensagemE;
    numeromensagemE.open("Númerodemensagens.txt");
    numeromensagemE >> nmensagens;
    numeromensagemE.close();
    fstream mensagens;
    mensagens.open("Mensagens.txt", ios::in);
    for(int m=0;m<=nmensagens;m++){
        getline (mensagens, condominio.mensagens[m]);
    }
    mensagens.close();
    ifstream nummoradoresE;
    nummoradoresE.open ("Númerodemoradores.txt");
    nummoradoresE >> condominio.nummoradores;
    nummoradoresE.close();
    ifstream nomecondE;
    nomecondE.open ("NomedoCondominio.txt");
    getline (nomecondE, condominio.nome);
    nomecondE.close();
    ifstream enderecoE;
    enderecoE.open ("Endereco.txt");
    getline (enderecoE, condominio.endereco);
    enderecoE.close();
    ifstream cepE;
    cepE.open ("CEP.txt");
    cepE >> condominio.cep;
    cepE.close();
    ifstream bairroE;
    bairroE.open("Bairro.txt");
    getline (bairroE, condominio.bairro);
    bairroE.close();
    ifstream cidadeE;
    cidadeE.open("Cidade.txt");
    getline (cidadeE, condominio.cidade);
    cidadeE.close();
    ifstream estadoE;
    estadoE.open ("Estado.txt");
    getline (estadoE, condominio.estado);
    estadoE.close();
    ifstream telefoneE;
    telefoneE.open ("TelefonedoCondominio.txt");
    telefoneE >> condominio.telefone;
    telefoneE.close();

    CadastroMorador morador[10000];
    fstream moradoresdocondominio;
    moradoresdocondominio.open("NomedosmoradoresCondomínio.txt", ios::in);
    for (int f=0;f<=contmorador;f++){
        getline (moradoresdocondominio, condominio.moradores[f]);
    }
    moradoresdocondominio.close();
    fstream numerodemorador;
    numerodemorador.open("Usuáriodosmoradores.txt", ios::in);
    for(int g=0;g<=contmorador;g++){
        numerodemorador >> morador[g].numero;
    }
    numerodemorador.close();
    fstream nomemorador;
    nomemorador.open ("NomedosMoradores.txt", ios::in);
    for(int e=0;e<=contmorador;e++){
        getline (nomemorador, morador[e].nome);
    }
    nomemorador.close();

    fstream cpfmorador;
    cpfmorador.open("CPFdosmoradores.txt", ios::in);
    for(int d=0;d<=contmorador;d++){
        cpfmorador >> morador[d].cpf;
    }
    cpfmorador.close();

    fstream rgmorador;
    rgmorador.open("RGdosmoradores.txt", ios::in);
    for(int c=0;c<=contmorador;c++){
        rgmorador >> morador[c].rg;
    }
    rgmorador.close();

    fstream estadocivilmorador;
    estadocivilmorador.open("EstadoCívilMorador.txt", ios::in);
    for(int b=0;b<=contmorador;b++){
        estadocivilmorador >> morador[b].estadocivil;
    }
    estadocivilmorador.close();

    fstream senhamorador;
    senhamorador.open("Senhadosmoradores.txt", ios::in);
    for(int a=0;a<=contmorador;a++){
        senhamorador >> morador[a].senha;
    }
    senhamorador.close();

    CadastroFuncionario funcionarios[1000];
    int numerodefuncionarios;
    ifstream nfunE;
    nfunE.open("Númerodefuncionários.txt");
    nfunE >> numerodefuncionarios;
    nfunE.close();

    fstream nomefuncionario;
    nomefuncionario.open("Nomedosfuncionários.txt", ios::in);
        for(int h=0;h<=numerodefuncionarios;h++){
            getline (nomefuncionario, funcionarios[h].nome);
        }
    nomefuncionario.close();

    fstream cpffuncionario;
    cpffuncionario.open("cpfdosfuncionários.txt", ios::in);
    for(int i=0;i<=numerodefuncionarios;i++){
        cpffuncionario >> funcionarios[i].cpf;
    }
    cpffuncionario.close();

    fstream funcaofuncionario;
    funcaofuncionario.open("Funçãodofuncionário.txt", ios::in);
    for(int j=0;j<=numerodefuncionarios;j++){
        getline (funcaofuncionario, funcionarios[j].funcao);
    }
    funcaofuncionario.close();

    fstream salariofuncionario;
    salariofuncionario.open("Salariodosfuncionarios.txt", ios::in);
    for(int k=0;k<=numerodefuncionarios;k++){
        salariofuncionario >> funcionarios[k].salario;
    }
    salariofuncionario.close();

        if(condominio.nome==""){
            system ("color 47");
            system ("cls");
            int op;
            cout << DesignCadastroCondominio();
            cout << "\n\nDigite a opção: ";
            cin >> op;
            if (op==0){
                return 0;
            }
            else {
                system ("cls");
                system ("color 37");
                cout << "CADASTRO DO ADMINISTRADOR/SINDICO!\n\n";
                cout << "OBS: - ESSE ADMINISTRADOR TERÁ CONTROLE TOTAL DAS AÇÕES DO CONDOMÍNIO \n";
                cout << "     - SOMENTE O ADMINISTRADOR PODERÁ ADICIONAR MORADORES AO CONDOMÍNIO \n";
                cout << "     - SOMENTE O ADMINISTRADOR PODERÁ MANDAR AVISOS PARA OS MORADORES \n";
                cout << "     - SOMENTE O ADMINISTRADOR PODERÁ ADICIONAR FUNCIONÁRIOS AO CONDOMÍNIO \n";
                cout << "     - SOMENTE O ADMINISTRADOR TERÁ ACESSO AS INFORMAÇÕES DE TODOS OS MORADORES \n\n";
                cout << "PODEMOS PROSSEGUIR COM A CONFIGURAÇÃO!!\n";
                system ("pause");
                system ("cls");
                cout << "NOME COMPLETO DO ADMINISTRADOR: ";
                ofstream nomeadminS;
                cin.ignore();
                nomeadminS.open("Nomedoadmin.txt");
                getline (cin, admin.nome);
                nomeadminS << admin.nome;
                nomeadminS.close();
                cout << "CPF: ";
                cin >> admin.cpf;
                ofstream cpfadminS;
                cpfadminS.open ("cpfadmin.txt");
                cpfadminS << admin.cpf;
                cpfadminS.close();
                cout << "RG: ";
                cin >> admin.rg;
                ofstream rgadminS;
                rgadminS.open ("rgadmin.txt");
                rgadminS << admin.rg;
                rgadminS.close();
                cout << "Estado Cívil: ";
                cin >> admin.estadocivil;
                ofstream estadociviladminS;
                estadociviladminS.open ("estadociviladmin.txt");
                estadociviladminS << admin.estadocivil;
                estadociviladminS.close();
                cout << "Ano de Nascimento: ";
                cin >> admin.idade;
                ofstream anoadminS;
                anoadminS.open ("idadeadmin.txt");
                anoadminS << admin.idade;
                anoadminS.close();
                cout << "Telefone: ";
                cin >> admin.contato[0];
                contadmintel++;
                ofstream contAS;
                contAS.open ("ContAdminTel.txt");
                contAS << contadmintel;
                contAS.close();
                fstream contatoadmin;
                contatoadmin.open ("contatoadmin.txt", ios::out|ios::app);
                contatoadmin << admin.contato[0] << endl;
                contatoadmin.close();
                system ("cls");
                cout << "ADMINISTRADOR CADASTRADO!!\n\nAGORA VAMOS PROSSEGUIR COM OS PASSOS!!\n\n";
                system ("pause");
                system("cls");
                cout << "CADASTRAMENTO DO CONDOMÍNIO!! \n\nINFORMAÇÕES DO CONDOMÍNIO!!\n";
                cout << "NOME DO CONDOMÍNIO: ";
                cin.ignore();
                getline (cin, condominio.nome);
                ofstream nomecondS;
                nomecondS.open ("NomedoCondominio.txt");
                nomecondS << condominio.nome;
                nomecondS.close();
                cout << "CEP: ";
                cin >> condominio.cep;
                ofstream cepS;
                cepS.open ("CEP.txt");
                cepS << condominio.cep;
                cepS.close();
                cout << "ENDEREÇO: ";
                cin.ignore();
                getline (cin, condominio.endereco);
                ofstream enderecoS;
                enderecoS.open ("Endereco.txt");
                enderecoS << condominio.endereco;
                enderecoS.close();
                cout << "BAIRRO: ";
                getline (cin, condominio.bairro);
                ofstream bairroS;
                bairroS.open("Bairro.txt");
                bairroS << condominio.bairro;
                bairroS.close();
                cout << "CIDADE: ";
                getline (cin, condominio.cidade);
                ofstream cidadeS;
                cidadeS.open("Cidade.txt");
                cidadeS << condominio.cidade;
                cidadeS.close();
                cout << "ESTADO: ";
                getline (cin, condominio.estado);
                ofstream estadoS;
                estadoS.open ("Estado.txt");
                estadoS << condominio.estado;
                estadoS.close();
                cout << "TELEFONE: ";
                cin >> condominio.telefone;
                ofstream telefoneS;
                telefoneS.open ("TelefonedoCondominio.txt");
                telefoneS << condominio.telefone << endl;
                telefoneS.close();
                system ("cls");
                cout << "CONFIGURAÇÕES DE LOGIN DO ADMINISTRADOR!!\n\n";
                cout << "OBS: COM ESSE LOGIN VOCÊ TERÁ ACESSO AO CONTROLE DE ADMINISTRADOR!!\n\n";
                cout << "VAMOS PROSSEGUIR!!\n\n";
                system ("pause");
                system ("cls");
                cout << "EMAIL: ";
                cin >> admin.email;
                ofstream emailadminS;
                emailadminS.open ("EmaildoAdmin.txt");
                emailadminS << admin.email;
                emailadminS.close();
                cout << "SENHA: ";
                cin >> admin.senha;
                ofstream senhaadminS;
                senhaadminS.open("SenhadoAdmin.txt");
                senhaadminS << admin.senha;
                senhaadminS.close();
                system ("cls");
                cout << "CADASTRO REALIZADO COM SUCESSO!!\n";
                system ("pause");
            }
        }

        else if(condominio.nome!=""){
            do{
                system("color 17");
                system ("cls");
                cout << DesignMenu();
                cin >> opcao;
                if(opcao==1){
                    system("cls");
                    system("color 17");
                    if(morador[0].numero==0){
                        cout << "NENHUM MORADOR CADASTRADO!!\n";
                        system("pause");
                    }
                    else{
                        string acheinumero="NAO";
                        int numero;
                        cout << "CADASTRO DE MORADOR!\n\n";
                        cout << "ATENÇÃO: VOCÊ PRECISA TER O NÚMERO DE MORADOR (GERADO PELO ADMIN)\n\n";
                        system("pause");
                        system("cls");
                        cout << "PARA TER CERTEZA QUE VOCÊ É MORADOR DO CONDOMÍNIO!\n";
                        cout << "INSIRA O NÚMERO DO MORADOR: ";
                        cin >> numero;
                        for(int n=0;n<=contmorador;n++){
                            if(numero==morador[n].numero){
                                if(morador[n].nome==""){
                                    system("cls");
                                    cout << "PROSSEGUIR COM O CADASTRO!!\n\n";
                                    system("pause");
                                    system("cls");
                                    cout << "INSIRA SEU NOME COMPLETO: ";
                                    cin.ignore();
                                    getline (cin, morador[n].nome);
                                    fstream nomemorador;
                                    nomemorador.open ("NomedosMoradores.txt", ios::out|ios::app);
                                    nomemorador << morador[n].nome << endl;
                                    nomemorador.close();
                                    cout << "CPF: ";
                                    cin >> morador[n].cpf;
                                    fstream cpfmorador;
                                    cpfmorador.open("CPFdosmoradores.txt", ios::out|ios::app);
                                    cpfmorador << morador[n].cpf << endl;
                                    cpfmorador.close();
                                    cout << "RG: ";
                                    cin >> morador[n].rg;
                                    fstream rgmorador;
                                    rgmorador.open("RGdosmoradores.txt", ios::out|ios::app);
                                    rgmorador << morador[n].rg << endl;
                                    rgmorador.close();
                                    cout << "Estado Cívil: ";
                                    cin >> morador[n].estadocivil;
                                    fstream estadocivilmorador;
                                    estadocivilmorador.open("EstadoCívilMorador.txt", ios::out|ios::app);
                                    estadocivilmorador << morador[n].estadocivil << endl;
                                    estadocivilmorador.close();
                                    system("cls");
                                    cout << "PARA FINALIZAR CRIE O SEU LOGIN!!\n\n";
                                    cout << "SEU USUÁRIO: " << morador[n].numero << endl;
                                    cout << "INSIRA A SENHA PARA LOGIN: ";
                                    cin >> morador[n].senha;
                                    fstream senhamorador;
                                    senhamorador.open("Senhadosmoradores.txt", ios::out|ios::app);
                                    senhamorador << morador[n].senha << endl;
                                    senhamorador.close();
                                    system("cls");
                                    cout << "MORADOR CADASTRADO COM SUCESSO!!\n\n";
                                    system("pause");
                                    acheinumero="SIM";
                                    break;
                                }
                                else {
                                    system("cls");
                                    cout << "ESSE NÚMERO DE MORADOR JÁ É CADASTRADO!!\n\n";
                                    acheinumero="SIM";
                                    system("pause");
                                }
                            }
                        }
                        if(acheinumero=="NAO"){
                            system("cls");
                            cout << "ESSE NÚMERO DE MORADOR NÃO ESTÁ CADASTRADO!! \n\n";
                            system("pause");
                        }
                    }
                }
                else if(opcao==2){
                  int opp;
                  do{
                    system("cls");
                    system("color 97");
                    cout << "LOGIN DO USUÁRIO!!\n\n";
                    cout << "(1) SOU ADMINISTRADOR!\n";
                    cout << "(2) SOU MORADOR!\n";
                    cout << "(0) RETORNAR AO MENU PRINCIPAL!\n\n";
                    cout << "INSIRA UMA OPÇÃO: ";
                    cin >> opp;
                    if(opp==1){
                        system("cls");
                        string usuariodedmin;
                        cout << "LOGIN DE ADMINISTRADOR!\n\n";
                        cout << "EMAIL: ";
                        cin >> usuariodedmin;
                        if(admin.email==usuariodedmin){
                            string senhadoadmin;
                            cout << "SENHA: ";
                            cin >> senhadoadmin;
                                if(senhadoadmin==admin.senha){
                                    system("cls");
                                    system("color 37");
                                    int opc;
                                  do{
                                    system("cls");
                                    cout << menuadmin();
                                    cin >> opc;
                                    if(opc==1){
                                        system("cls");
                                        cout << "ADICIONE UM MORADOR AO CONDOMÍNIO! \n\n";
                                        cout << "NOME DO MORADOR: ";
                                        cin.ignore();
                                        getline (cin, condominio.moradores[condominio.nummoradores]);
                                        fstream moradoresdocondominio;
                                        moradoresdocondominio.open("NomedosmoradoresCondomínio.txt", ios::out|ios::app);
                                        moradoresdocondominio << condominio.moradores[condominio.nummoradores] << endl;
                                        moradoresdocondominio.close();
                                        system ("cls");
                                        cout << "MORADOR REGISTRADO!!\n\n";
                                        morador[contmorador].numero=2020000+contmorador;
                                        cout << "NÚMERO DE USUÁRIO PARA O MORADOR: " << morador[contmorador].numero << endl;
                                        cout << "\nOBS: ESSE NÚMERO DEVE SER REPASSADO PARA O MORADOR CONSEGUIR ACESSO AO CONTROLE!!\n";
                                        fstream numerodemorador;
                                        numerodemorador.open("Usuáriodosmoradores.txt", ios::out|ios::app);
                                        numerodemorador << morador[contmorador].numero << endl;
                                        numerodemorador.close();
                                        contmorador++;
                                        ofstream contMS;
                                        contMS.open("ContMorador.txt");
                                        contMS << contmorador;
                                        contMS.close();
                                    }
                                    else if (opc==2){
                                        system("cls");
                                        cout << "ADICIONE OS FUNCIONÁRIOS DO CONDOMÍNIO!\n\n";
                                        cout << "NOME COMPLETO DO FUNCIONÁRIO: ";
                                        cin.ignore();
                                        getline (cin, funcionarios[numerodefuncionarios].nome);
                                        fstream nomefuncionario;
                                        nomefuncionario.open("Nomedosfuncionários.txt", ios::out|ios::app);
                                        nomefuncionario << funcionarios[numerodefuncionarios].nome << endl;
                                        nomefuncionario.close();
                                        cout << "CPF: ";
                                        cin >> funcionarios[numerodefuncionarios].cpf;
                                        fstream cpffuncionario;
                                        cpffuncionario.open("cpfdosfuncionários.txt", ios::out|ios::app);
                                        cpffuncionario << funcionarios[numerodefuncionarios].cpf << endl;
                                        cpffuncionario.close();
                                        cout << "FUNÇÃO NO CONDOMÍNIO (EX: PORTEIRO, FAXINEIRO ETC...): ";
                                        cin.ignore();
                                        getline (cin, funcionarios[numerodefuncionarios].funcao);
                                        fstream funcaofuncionario;
                                        funcaofuncionario.open("Funçãodofuncionário.txt", ios::out|ios::app);
                                        funcaofuncionario << funcionarios[numerodefuncionarios].funcao << endl;
                                        funcaofuncionario.close();
                                        cout << "SÁLARIO DO FUNCIONÁRIO: ";
                                        cin >> funcionarios[numerodefuncionarios].salario;
                                        salariofuncionarios=funcionarios[numerodefuncionarios].salario+salariofuncionarios;
                                        ofstream salariofuncS;
                                        salariofuncS.open("despesascomfuncionarios.txt");
                                        salariofuncS << salariofuncionarios;
                                        salariofuncS.close();
                                        fstream salariofuncionario;
                                        salariofuncionario.open("Salariodosfuncionarios.txt", ios::out|ios::app);
                                        salariofuncionario << funcionarios[numerodefuncionarios].salario << endl;
                                        salariofuncionario.close();
                                        numerodefuncionarios++;
                                        ofstream nfunS;
                                        nfunS.open("Númerodefuncionários.txt");
                                        nfunS << numerodefuncionarios;
                                        nfunS.close();
                                        system("cls");
                                        cout << "FUNCIONÁRIO CADASTRADO COM SUCESSO!!\n\n";
                                    }
                                    else if(opc==3){
                                        system("cls");
                                        cout << "CAIXA DE MENSAGENS!!\n\n";
                                        cout << "MENSAGENS DO ADMINISTRADOR!\n\n";
                                        if(nmensagens==0){
                                            cout << "NENHUMA MENSAGEM REGISTRADA!!\n\n";
                                        }
                                        else {
                                            for(int n=0;n<nmensagens;n++){
                                                cout << n+1 << ". " << condominio.mensagens[n] << endl;
                                            }
                                        }
                                        cout << "ADICIONAR MENSAGEM?\n";
                                        cout << "(1) SIM (2) NÃO\n\n";
                                        int sn;
                                        cin >> sn;
                                        if(sn==1){
                                            system("cls");
                                            cout << "TODOS OS MORADORES DO CONDOMÍNIO IRÃO VER O AVISO!!\n";
                                            cout << "OBS: EVITE ACENTOS E SEJA BREVE NO SEU AVISO!\n\n";
                                            cin.ignore();
                                            getline(cin, condominio.mensagens[nmensagens]);
                                            fstream mensagens;
                                            mensagens.open("Mensagens.txt", ios::out|ios::app);
                                            mensagens << condominio.mensagens[nmensagens] << endl;
                                            mensagens.close();
                                            nmensagens++;
                                            ofstream numeromensagemS;
                                            numeromensagemS.open("Númerodemensagens.txt");
                                            numeromensagemS << nmensagens;
                                            numeromensagemS.close();
                                        }
                                    }
                                    else if(opc==4){
                                        system("cls");
                                        cout << "DESPESAS DO CONDOMÍNIO!!\n\n";
                                        if(numerodespesas==0){
                                            cout << "NENHUMA DESPESA ADICIONADA!!\n";
                                        }
                                        else {
                                            for(int q=0;q<numerodespesas;q++){
                                                cout << q+1 << "° " << condominio.despesas[q] << "    GASTO: " << condominio.gastosdespesa[q] << endl;
                                            }
                                            cout << "\nGASTOS GERAIS (INCLUINDO SALÁRIO DOS FUNCIONÁRIOS): " << gastosgeral << endl;
                                        }
                                        cout << "\nADICIONAR DESPESAS!!\n\n";
                                        cout << "(1) SIM    (2)NÃO\n\n";
                                        int sina;
                                        cin >> sina;
                                        if(sina==1){
                                            system("cls");
                                            cout << "ADICIONE UMA NOVA DESPESA!!\n\n";
                                            cout << "DESPESA: ";
                                            cin.ignore();
                                            getline (cin, condominio.despesas[numerodespesas]);
                                            fstream despesas;
                                            despesas.open("Despesasdocondominio.txt", ios::out|ios::app);
                                            despesas << condominio.despesas[numerodespesas] << endl;
                                            despesas.close();
                                            cout << "GASTO COM ESSA DESPESA: ";
                                            cin >> condominio.gastosdespesa[numerodespesas];
                                            fstream gastodespesa;
                                            gastodespesa.open("Gastosdasdespesas.txt", ios::out|ios::app);
                                            gastodespesa << condominio.gastosdespesa[numerodespesas] << endl;
                                            gastodespesa.close();
                                            despesasgerais=despesasgerais+condominio.gastosdespesa[numerodespesas];
                                            ofstream despesasgeraisS;
                                            despesasgeraisS.open("Despesasgerais.txt");
                                            despesasgeraisS << despesasgerais;
                                            despesasgeraisS.close();
                                            gastosgeral=despesasgerais+salariofuncionarios;
                                            ofstream gastosS;
                                            gastosS.open("Gastosgerais.txt");
                                            gastosS << gastosgeral;
                                            gastosS.close();
                                            numerodespesas++;
                                            ofstream ndespesasS;
                                            ndespesasS.open("Númerodedespesas.txt");
                                            ndespesasS << numerodespesas;
                                            ndespesasS.close();
                                        }
                                    }
                                    else if(opc==5){
                                        system("cls");
                                        if(morador[0].nome==""){
                                            cout << "NENHUM MORADOR CADASTRADO NO CONDOMÍNIO!!\n";
                                        }
                                        else {
                                            cout << "LISTA DOS MORADORES DO CONDOMÍNIO!\n\n";
                                            for(int r=0;r<contmorador;r++){
                                                cout << morador[r].numero << " --> " << morador[r].nome << " TELEFONE: " << endl;
                                            }
                                        }
                                    }
                                    else if(opc==6){
                                        system("cls");
                                        if(funcionarios[0].nome==""){
                                            cout << "NENHUM FUNCIONÁRIO CADASTRADO NO CONDOMÍNIO!!\n";
                                        }
                                        else {
                                            cout << "LISTA DOS FUNCIONÁRIOS DO CONDOMÍNIO!\n\n";
                                            for(int s=0;s<numerodefuncionarios;s++){
                                                cout << funcionarios[s].funcao << ": " << funcionarios[s].nome << " SALÁRIO: " << funcionarios[s].salario << endl;
                                            }
                                        }
                                    }
                                    else if(opc==7){
                                        system("cls");
                                        cout << designcondominio(condominio.nome, contmorador, gastosgeral, condominio.estado, condominio.endereco, condominio.bairro, condominio.cidade);
                                    }
                                    else if(opc==8){
                                        system("cls");
                                        cout << "DADOS PESSOAIS!!\n\n";
                                        cout << "NOME COMPLETO: " << admin.nome << endl;
                                        cout << "CPF: " << admin.cpf << endl;
                                        cout << "RG: " << admin.rg << endl;
                                        cout << "ESTADO CÍVIL: " << admin.estadocivil << endl;
                                        cout << "ANO DE NASCIMENTO: " << admin.idade << endl;
                                        cout << "CONTATO: " << condominio.telefone << endl;
                                    }
                                    else if(opc==9){
                                        int opca;
                                        do{
                                            system("cls");
                                            cout << "CONFIGURAÇÕES DA CONTA!\n\n";
                                            cout << "(1) ALTERAR USUÁRIO/EMAIL!\n";
                                            cout << "(2) ALTERAR SENHA!\n";
                                            cout << "(3) ALTERAR CONTATO!\n";
                                            cout << "(0) SAIR!!\n\n";
                                            cout << "O QUE VOCÊ PRETENDE FAZER? ";
                                            cin >> opca;
                                            if(opca==1){
                                                system("cls");
                                                cout << "INSIRA UM NOVO USUÁRIO: ";
                                                cin >> admin.email;
                                                ofstream emailadminS;
                                                emailadminS.open ("EmaildoAdmin.txt");
                                                emailadminS << admin.email;
                                                emailadminS.close();
                                                system("cls");
                                                cout << "USUÁRIO ALTERADO COM SUCESSO!!\n\n";
                                            }
                                            else if(opca==2){
                                                system("cls");
                                                cout << "INSIRA UMA NOVA SENHA: ";
                                                cin >> admin.senha;
                                                ofstream senhaadminS;
                                                senhaadminS.open("SenhadoAdmin.txt");
                                                senhaadminS << admin.senha;
                                                senhaadminS.close();
                                                system("cls");
                                                cout << "SENHA ALTERADA COM SUCESSO!!\n\n";
                                            }
                                            else if(opca==3){
                                                system("cls");
                                                cout << "INSIRA UM NOVO CONTATO: ";
                                                cin >> admin.contato;
                                                ofstream telefoneS;
                                                telefoneS.open ("TelefonedoCondominio.txt");
                                                telefoneS << condominio.telefone << endl;
                                                telefoneS.close();
                                                system("cls");
                                                cout << "CONTATO ALTERADO COM SUCESSO!!\n\n";
                                            }
                                            system("pause");
                                        }while(opca!=0);
                                    }
                                    cout << endl;
                                    system("pause");
                                 }while (opc!=0);
                                }
                                else{
                                    system("cls");
                                    cout << "SENHA INCORRETA!!\n\n";
                                    system ("pause");
                                }
                            }
                        else {
                            system("cls");
                            cout << "EMAIL INCORRETO OU VOCÊ NÃO É ADMINISTRADOR\n\n";
                            system("pause");
                        }
                    }
                    else if(opp==2){
                        system("cls");
                        int numerousu;
                        string achonumero="NAO";
                        cout << "LOGIN DO MORADOR!\n";
                        cout << "USUÁRIO: ";
                        cin >> numerousu;
                        for(int u=0;u<=contmorador;u++){
                            if(numerousu==morador[u].numero){
                                achonumero="SIM";
                                string senhademorador;
                                cout << "INSIRA SUA SENHA: ";
                                cin >> senhademorador;
                                if(senhademorador==morador[u].senha){
                                    int opcc;
                                    do{
                                    system("cls");
                                    system("color 57");
                                    cout << menumorador();
                                    cout << condominio.mensagens[nmensagens-1];
                                    cout << "\n\nO QUE PRETENDE FAZER? ";
                                    cin >> opcc;
                                        if(opcc==1){
                                            system("cls");
                                            cout << "DADOS DO MORADOR!!\n\n";
                                            cout << "NOME COMPLETO: " << morador[u].nome << endl;
                                            cout << "CPF: " << morador[u].cpf << endl;
                                            cout << "RG: " << morador[u].rg << endl;
                                            cout << "ESTADO CÍVIL: " << morador[u].estadocivil << endl;
                                        system("pause");
                                        }
                                        else if(opcc==2){
                                            system("cls");
                                            cout << designcondominio(condominio.nome, contmorador, gastosgeral, condominio.estado, condominio.endereco, condominio.bairro, condominio.cidade);
                                            system("pause");
                                        }
                                        else if(opcc==3){
                                            system("cls");
                                            cout << "CAIXA DE MENSAGEM!!\n\n";
                                            for(int v=0;v<nmensagens;v++){
                                                cout << v+1 << "° " << condominio.mensagens[v] << "\n\n";
                                            }
                                            system("pause");
                                        }
                                        else if(opcc==4){
                                            system("cls");
                                            cout << "DESPESAS GERAIS DO CONDOMÍNIO!!\n\n";
                                            for(int y=0;y<numerodespesas;y++){
                                                cout << y+1 << "° " << condominio.despesas[y] << " GASTO: " << condominio.gastosdespesa[y] << endl;
                                            }
                                            cout << "\nGASTOS GERAIS DO CONDOMÍNIO (INCLUINDO SALÁRIO DOS FUNCIONÁRIOS): R$" << gastosgeral << endl;
                                            system("pause");
                                        }
                                        else if(opcc==5){
                                            system("cls");
                                            cout << "LISTA DOS MORADORES DO CONDOMÍNIO (INCLUINDO VOCÊ!!)\n\n";
                                            for(int z=0;z<contmorador;z++){
                                                cout << z+1 << "° " << morador[z].nome << endl;
                                            }
                                            system("pause");
                                        }
                                        else if(opcc==6){
                                            system("cls");
                                            cout << "LISTA DOS FUNCIONÁRIOS DO CONDOMÍNIO!!\n\n";
                                            for(int ab=0;ab<numerodefuncionarios;ab++){
                                                cout << funcionarios[ab].funcao << ": " << funcionarios[ab].nome << " SALÁRIO: " << "R$ " << funcionarios[ab].salario << endl;
                                            }
                                            system("pause");
                                        }
                                    }while (opcc!=0);
                                }
                                else{
                                    system("cls");
                                    cout << "SENHA INCORRETA!!\n\n";
                                    system("pause");
                                }
                            }

                        }
                        if(achonumero=="NAO"){
                            system("cls");
                            cout << "NÚMERO NÃO ESTÁ CADASTRADO!!\n\n";
                            system("pause");
                        }
                    }

                  }while (opp!=0);
                }
            }while (opcao!=0);
        }
}

string DesignCadastroCondominio(){
    cout << "SEJA BEM VINDO AO SISTEMA DE CONTROLE DE CONDOMÍNIO!! \n\n";
    cout << "PRIMEIROS PASSOS PARA A CONFIGURAÇÃO DO CONTROLE! \n\n";
    cout << "1. CADASTRO DO ADMINISTRADOR/SINDICO \n";
    cout << "2. CADASTRO DO CONDOMÍNIO \n";
    cout << "3. CRIAR LOGIN DE USUÁRIO \n\n";
    cout << "PRETENDE SEGUIR COM OS PASSOS!! \n";
    return "1.SIM               0. NÃO";
}

string DesignMenu(){
    cout << "SISTEMA DE CONTROLE DE CONDOMÍNIO!! \n\n\n";
        cout << " ___________________________\n";
        cout << "|                           |\n";
        cout << "|      SEJA BEM VINDO!!     |\n";
        cout << "|   ___   ___   ___   ___   |\n";
        cout << "|  |   | |   | |   | |   |  |\n";
        cout << "|  |___| |___| |___| |___|  |\n";
        cout << "|   ___   ___   ___   ___   |\n";
        cout << "|  |   | |   | |   | |   |  |\n";
        cout << "|  |___| |___| |___| |___|  |\n";
        cout << "|   ___   ___   ___   ___   |\n";
        cout << "|  |   | |   | |   | |   |  |         (1) CRIAR LOGIN PARA MORADOR!\n";
        cout << "|  |___| |___| |___| |___|  |\n";
        cout << "|   ___   ___   ___   ___   |         (2) FAZER LOGIN!\n";
        cout << "|  |   | |   | |   | |   |  |\n";
        cout << "|  |___| |___| |___| |___|  |         (0) SAIR DO SISTEMA!\n";
        cout << "|   ___   ___   ___   ___   |\n";
        cout << "|  |   | |   | |   | |   |  |\n";
        cout << "|  |___| |___| |___| |___|  |\n";
        cout << "|   ___   ___   ___   ___   |\n";
        cout << "|  |   | |   | |   | |   |  |\n";
        cout << "|  |___| |___| |___| |___|  |\n";
        cout << "|   ___   ___   ___   ___   |\n";
        cout << "|  |   | |   | |   | |   |  |\n";
        cout << "|  |___| |___| |___| |___|  |\n";
        cout << "|   ___   ___   ___   ___   |\n";
        cout << "|  |   | |   | |   | |   |  |\n";
        cout << "|  |___| |___| |___| |___|  |\n";
        cout << "|        ___________        |\n";
        cout << "|       |     |     |       |\n";
        cout << "|       |    .|.    |       |\n";
        cout << "|       |     |     |       |\n";
        cout << "|_______|_____|_____|_______|\n\n";
        return "INSIRA UMA OPÇÃO: ";
}

string menuadmin(){
        cout << "SISTEMA DE CONTROLE DO ADMINISTRADOR!!\n\n";
        cout << "(1) ADICIONAR MORADORES \n";
        cout << "(2) ADICIONAR FUNCIONÁRIOS \n";
        cout << "(3) CAIXA DE MENSAGEM \n";
        cout << "(4) DESPESAS DO CONDOMÍNIO \n";
        cout << "(5) LISTAR MORADORES\n";
        cout << "(6) LISTAR FUNCIONÁRIOS \n";
        cout << "(7) INFORMAÇÕES DO CONDOMÍNIO \n";
        cout << "(8) DADOS DO ADMINISTRADOR \n";
        cout << "(9) ALTERAR CONFIGURAÇÕES\n";
        cout << "(0) SAIR DA CONTA!!\n\n";
        return "O QUE PRETENDE FAZER? ";
}

string menumorador(){
    cout << "MENU DO MORADOR!!\n\n";
    cout << "(1) MEUS DADOS\n";
    cout << "(2) INFORMAÇÕES DO CONDOMÍNIO\n";
    cout << "(3) CAIXA DE MENSAGEM\n";
    cout << "(4) DESPESAS DO CONDOMÍNIO\n";
    cout << "(5) TODOS OS MORADORES\n";
    cout << "(6) TODOS OS FUNCIONÁRIOS\n";
    cout << "(0) SAIR DA CONTA\n\n";
    return "MENSAGEM MAIS RECENTE!!\n\n";
}

string designcondominio(string var1, int var2, int var3, string var4, string var5, string var6, string var7){
        cout << "INFORMAÇÕES DO CONDOMÍNIO \n\n";
        cout << "           ______________" << endl;
        cout << "          |::::::::::::::|           INFORMAÇÕES DO CONDOMÍNIO!" << endl;
        cout << "          |::::::::::::::|             NOME DO CONDOMÍNIO: " << var1 << endl;
        cout << "   _______|::::::::::::::|_______      NÚMERO DE MORADORES: " << var2 << endl;
        cout << "  |:::::::|::::::::::::::|:::::::|     GASTOS GERAIS: " << var3 << " R$" << endl;
        cout << "  |:::::::|::::::::::::::|:::::::|" << endl;
        cout << "  |:::::::|::::::::::::::|:::::::|   LOCALIZAÇÃO!!" << endl;
        cout << "  |:::::::|::::::::::::::|:::::::|     ESTADO: " << var4 << endl;
        cout << "  |:::::::|::::::::::::::|:::::::|     ENDEREÇO: " << var5 << endl;
        cout << "  |:::::::|::::::::::::::|:::::::|     BAIRRO: " << var6 << endl;
        cout << "  |::::: _|::::  __  ::::|_ :::::|     CIDADE: " << var7  << endl;
        cout << "==|     |-|     |--|     |-|     |==" << endl;
        cout << "====================================" << endl;
        cout << "====================================" << endl;
        return "INFORMAÇÕES FORNECIDAS PELO ADMINISTRADOR/SÍNDICO! \n\n";
}

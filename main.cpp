#include <iostream>
#include <vector>
using namespace std;

//Classe Cliente
class Cliente
{
private:
    string agencia;
    string nome;
    string senha;
    string cpf;
    double saldo;
public:
    Cliente(const string agencia,const string nome,const string senha,const string cpf,const double saldo)
    {
        this->agencia = agencia;
        this->nome = nome;
        this->senha = senha;
        this->cpf = cpf;
        this->saldo = saldo;
    }

    string getAgencia()
    {
        return agencia;
    }

    string getNome()
    {
        return nome;
    }

    string getSenha()
    {
        return senha;
    }

    void setSenha(const string &senha)
    {
        this->senha = senha;
    }

    string getCPF()
    {
        return cpf;
    }

    double getSaldo()
    {
        return saldo;
    }

    void Deposito(const double &v)
    {
        this->saldo = this->saldo + v;
    }
    void Saque(const double &v)
    {
        this->saldo = this->saldo - v;
    }
};


//Classe Extrato
class Extrato
{
private:
    string cpf;
    string op;
    double valor;
public:
    Extrato(const string cpf, const string op, const double valor)
    {
        this->cpf=cpf;
        this->op=op;
        this->valor=valor;
    }
    void setNome(const string &nome)
    {
        this->cpf=nome;
    }

    string getCPF()
    {
        return cpf;
    }

    void setOp(const string &op)
    {
        this->op=op;
    }

    string getOp()
    {
        return op;
    }

    void setValor(const double &valor)
    {
        this->valor=valor;
    }

    double getValor()
    {
        return valor;
    }
};



//Classe Banco: Lista de Clientes / Extratos
class Banco
{
public:
    std::vector<Cliente*> Clientes = std::vector<Cliente*>();
    std::vector<Extrato*> Extratos = std::vector<class Extrato*>();
    Banco() {};


    void cadastraCliente(Cliente *C)
    {
        Clientes.push_back(C);
    }

    void registraExtrato(Extrato *E)
    {
        Extratos.push_back(E);
    }

    void apagaCliente(string cpf)
    {
        bool x = false;
        int i = 0;
        while(i<Clientes.size())
        {
            if(Clientes[i]->getCPF()==cpf)
            {
                Clientes.erase(Clientes.begin() + i);
                cout<<"Registro de Cliente encerrado"<<endl;
                x = true;

            }
            i++;
        }
        if(!x)
            cout<<"Registro de Cliente Nao Encontrado"<<endl;
    }


    void Deposito(string cpf, double valor)
    {
        bool x = false;
        int i = 0;
        while(i<Clientes.size())
        {
            if(Clientes[i]->getCPF()==cpf)
            {
                Clientes[i]->Deposito(valor);
                x = true;
            }
            i++;
        }
        if(!x)
            cout<<"CPF Invalido"<<endl;
    }


    void Saque(string cpf, string senha, double valor)
    {
        bool x = false;
        int i = 0;
        while(i<Clientes.size())
        {
            if(Clientes[i]->getCPF()==cpf && Clientes[i]->getSenha()==senha)
            {
                Clientes[i]->Saque(valor);
                cout<<"Saque Realizado"<<endl;
                x = true;
            }
            i++;
        }
        if(!x)
            cout<<"Senha Invalida"<<endl;
    }


    void Extrato(string cpf)
    {
        bool x = false;
        int i = 0;
        int j = 0;
        while(i<Extratos.size())
        {
            if(Extratos[i]->getCPF()==cpf)
            {
                while(j<Clientes.size())
                {
                    if(Clientes[j]->getCPF()==cpf)
                    {
                        cout<<"EXTRATO BANCARIO"<<endl;
                        cout<<"Nome: "<<Clientes[j]->getNome()<<endl;
                        cout <<"CPF: " << Extratos[i]->getCPF()<<endl;
                        cout<<"\n";
                    }
                    j++;
                }
                cout << "Operacao: " << Extratos[i]->getOp() << endl;
                cout << "Valor: R$" << Extratos[i]->getValor() << endl;
                x = true;
            }
            i++;
        }
        if(!x){
          cout<<"Sem Movimento Bancario"<<endl;
        }
    }


    void mostraCliente(string nome)
    {
        bool x = false;
        int i = 0;
        while(i<Clientes.size())
        {
            if(Clientes[i]->getNome()==nome)
            {
                cout << "Agencia: " << Clientes[i]->getAgencia()<<endl;
                cout<<"Nome: " << Clientes[i]->getNome()<<endl;
                cout<<"CPF: " << Clientes[i]->getCPF()<<endl;
                cout<<"Saldo Atual: " << Clientes[i]->getSaldo()<<endl;
                cout<<"Senha: " << Clientes[i]->getSenha()<<endl;
                x = true;
            }
            i++;
            cout<<"\n";
        }
        if(!x)
            cout<<"Registro de Cliente Nao Encontrado"<<endl;
    }

    void listaClientes()
    {
        int i = 0;
        while(i<Clientes.size())
        {
            cout << "Agencia: " << Clientes[i]->getAgencia()<<endl;
            cout << "Nome: " << Clientes[i]->getNome() << endl;
            cout << "CPF: " << Clientes[i]->getCPF() << endl;
            cout << "Saldo Atual: " << Clientes[i]->getSaldo() << endl;
            cout<<"Senha: "<<Clientes[i]->getSenha()<<endl;
            cout<<"\n\n";
            i++;
        }
    }

    void clientesAgencia(string agencia)
    {
        bool x = false;
        int i = 0;
        while(i<Clientes.size())
        {
            if(Clientes[i]->getAgencia()==agencia)
            {
                cout << "Agencia: " << Clientes[i]->getAgencia()<<endl;
                cout<<"Nome: "<<Clientes[i]->getNome()<<endl;
                cout<<"CPF: "<<Clientes[i]->getCPF()<<endl;
                cout<<"Saldo Atual: "<<Clientes[i]->getSaldo()<<endl;
                cout<<"Senha: "<<Clientes[i]->getSenha()<<endl;
                x = true;
            }
            i++;
            cout<<"\n";
        }
        if(!x)
            cout<<"Agencia sem registros"<<endl;
    }

    bool verificaCPF(string cpf)
    {
        bool x = false;
        if(!Clientes.empty())
        {
            int i = 0;
            while (i < Clientes.size())
            {
                if (Clientes[i]->getCPF() == cpf)
                {
                    x = true;
                }
                i++;
            }
            return x;
        }
        else
        {
            return x;
        }
    }

    bool verificaSenha(string cpf, string senha){
      bool x = false;
      if(!Clientes.empty()){
        int i=0;
        while(i<Clientes.size()){
           if (Clientes[i]->getCPF() == cpf && Clientes[i]->getSenha()==senha)
            {
                    x = true;
            }
            i++;
        }
        return x;
      }
      else{
        return x;
      }
    }

};



int main()
{
    string agencia, nome, cpf;
    string senha;
    double saldo, valor;
    Banco *b = new Banco();
    int op;
    
    cout<<"1-Cadastrar Cliente."<<endl;
    cout<<"2-Realizar Deposito."<<endl;
    cout<<"3-Realizar Saque."<<endl;
    cout<<"4-Mostrar Informacoes de Cliente."<<endl;
    cout<<"5-Mostrar Lista de Clientes do Banco."<<endl;
    cout<<"6-Mostrar Clientes de Uma Determinada Agencia."<<endl;
    cout<<"7-Gerar Extrato de Cliente"<<endl;
    cout<<"8-Apagar Cadastro"<<endl;
    cout<<"0-Sair."<<endl;
    

    cin>>op;
    while(op!=0)
    {
        switch(op)
        {
        case 1:
        {
            cout<<"Insira o numero da Agencia na qual e Feita o Cadastro: ";
            cin>>agencia;
            cout<<"Insira o Nome: ";
            cin.ignore();
            getline (cin, nome);
            cout<<"Qual Senha Deseja:(6 digitos) ";
            cin>>senha;
            if(senha.length()!=6)
            {
                cout<<"Senha Invalida"<<endl;
                break;
            }
            cout<<"Insira o Numero de CPF:(11 digitos) ";
            cin>>cpf;
            if(cpf.length()!=11)
            {
                cout<<"CPF Invalido"<<endl;
                break;
            }
            if(b->verificaCPF(cpf)==true)
            {
                cout<<"CPF Ja Registrado no Sistema"<<endl;
                break;
            }
            cout<<"Insira o saldo Inicial Que Deseja: ";
            cin>>saldo;
            Cliente *c = new Cliente(agencia,nome, senha, cpf, saldo);
            b->cadastraCliente(c);
            cout << endl << "Cadastro realizado com sucesso"<<endl;

            break;
        }

        case 2:
        {
            if(!b->Clientes.empty())
            {
                cout << "Insira o Seu CPF: ";
                cin >> cpf;
                cout << "Qual Valor Deseja Depositar? ";
                cin >> valor;
                b->Deposito(cpf, valor);
                Extrato *e = new Extrato(cpf, "Deposito", valor);
                b->registraExtrato(e);
                cout << endl << "Deposito realizado com sucesso"<<endl;
                getchar();
                break;
            }
            else
            {
                cout << "Lista de Clientes Vazia" << endl;
                getchar();
                break;
            }
        }

        case 3:
        {
            if(!b->Clientes.empty())
            {
                cout << "Insira o seu cpf: ";
                cin >> cpf;
                if(!b->verificaCPF(cpf)){
                  cout<<"CPF invalido"<<endl;
                  break;
                }
                cout << "Digite Sua Senha: ";
                cin >> senha;
                if(!b->verificaSenha(cpf, senha)){
                    cout<<"Senha Invalida"<<endl;
                    break;
                }
                cout << "Qual Valor Deseja Sacar? ";
                cin >> valor;
                b->Saque(cpf, senha, valor);
                Extrato *e1 = new Extrato(cpf, "Saque", valor);
                b->registraExtrato(e1);
                break;
            }
            else
            {
                cout << "Lista de Clientes Vazia" << endl;
                break;
            }
        }

        case 4:
        {
            if(!b->Clientes.empty())
            {
                cout << "Insira o Nome do Cliente Desejado: ";
                cin.ignore();
                getline (cin, nome, '\n');
                b->mostraCliente(nome);
                break;
            }
            else
            {
                cout << "Lista de Clientes Vazia" << endl;
                break;
            }
        }

        case 5:
        {
            if(!b->Clientes.empty())
            {
                b->listaClientes();
                break;
            }
            else
            {
                cout << "Lista de Clientes Vazia" << endl;
                break;
            }
        }

        case 6:
        {
            if(!b->Clientes.empty())
            {
                cout<<"Insira a Agencia na Qual Deseja Ver os Clientes: ";
                cin>>agencia;
                b->clientesAgencia(agencia);
                break;
            }
            else
            {
                cout << "Lista de Clientes Vazia" << endl;
                break;
            }
        }

        case 7:
        {
            if(!b->Clientes.empty())
            {
                cout << "Insira o CPF Para Gerar o Extrato: ";
                cin >> cpf;
                if(b->verificaCPF(cpf) == true)
                {
                    b->Extrato(cpf);
                    break;
                }
                else
                {
                    cout << "Registro Nao Encontrado" << endl;
                }
            }
            else
            {
                cout << "Lista de Clientes Vazia" << endl;
                break;
            }
        }

        case 8:
        {
            if(!b->Clientes.empty())
            {
                cout<<"Insira o CPF do Cliente no Qual Deseja Exluir o Cadastro: ";
                cin>>cpf;
                b->apagaCliente(cpf);
                cout << endl << "Cadastro excluido com sucesso"<<endl;
                break;
            }
            else
            {
                cout << "Lista de Clientes Vazia" << endl;
                break;
            }
        }

        default:{
          cout<<"Opcao Invalida."<<endl;
          break;
        }
        }
        
        /*cout << endl<< "Aperte o teclado enter para prosseguir..."<<endl;
        //limpador te tela
        system("clear");*/
        
        cout<<"\n\n";
        cout<<"1-Cadastrar Cliente."<<endl;
        cout<<"2-Realizar Deposito."<<endl;
        cout<<"3-Realizar Saque."<<endl;
        cout<<"4-Mostrar Informacoes de Cliente."<<endl;
        cout<<"5-Mostrar Lista de Clientes do Banco."<<endl;
        cout<<"6-Mostrar Clientes de Uma Determinada Agencia."<<endl;
        cout<<"7-Gerar Extrato de Cliente"<<endl;
        cout<<"8-Apagar Cadastro"<<endl;
        cout<<"0-Sair."<<endl;
        cout<<"\n\n";

        cin>>op;
    }
    return 0;
}

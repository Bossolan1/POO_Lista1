#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Paciente
{
    private:
        string nomePaciente, cpf, dataNascimento;
    public:
        Paciente(string nomePaciente, string cpf, string dataNascimento): nomePaciente(nomePaciente), cpf(cpf), dataNascimento(dataNascimento){
        cout << "Paciente'" << nomePaciente << "'criado\n";}

        ~Paciente(){cout << "Paciente'" << nomePaciente << "'Apagado!\n";}

        const string getNomePaciente() const { return nomePaciente; }
        const string getCpf() const { return cpf; }
};

class Medico
{
    private:
        string nomeMedico, crm, especialidade;
    public:
        Medico(string nomeMedico, string crm, string especialidade): nomeMedico(nomeMedico), crm(crm), especialidade(especialidade){
        cout << "Medico '" << nomeMedico << "' criado!\n";}

        ~Medico(){ cout << "Medico'" << nomeMedico << "'Apagado!\n";}

        const string getNomeMedico() const { return nomeMedico; }
        const string getEspecialidade() const { return especialidade; }
};

class Prontuario {
    private:
        string codProntuario, descricao;
        Paciente* paciente;
        Medico* medico;
    public:
        Prontuario(string codProntuario, string descricao, Paciente* paciente, Medico* medico) : codProntuario(codProntuario), descricao(descricao), paciente(paciente), medico(medico){
            cout << "Prontuario'" << codProntuario << "' Criado com sucesso!\n";
        }
        ~Prontuario(){cout << "Prontuario:'" << codProntuario << "'Deletado com sucesso!\n";}
        void imprimirProtuario()
        {
            cout << "\n-------------------------------";
            cout << "\n-----------Prontuario----------";
            cout << "\n-------------------------------";
            cout << "\nCod:'" << codProntuario << "'\n";
            cout << "\nNome Paciente:'" << paciente->getNomePaciente() << "'\n";
            cout << "\nCPF  Paciente:'" << paciente->getCpf() << "'\n";
            cout << "\nNome Medico  :'" << medico->getNomeMedico() << "'\n";
            cout << "\nEspecilidade :'" << medico->getEspecialidade() << "'\n";
            cout << "\nDescricao    :'" << descricao << "'\n";
            cout << "\n-------------------------------\n";
        }
};


int main() {
    Paciente paciente("nomePaciente","123.123.123.12","1999-01-01");
    Medico medico("nomeMedico","123123123-12","especialidade");
    Prontuario prontuario("01", "bla bla bla", &paciente, &medico);
    prontuario.imprimirProtuario();

    return 4;
}

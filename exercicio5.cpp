#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Professor
{
  private:
    string nomeProfessor, cpf, especialidade;
  public:
    Professor(string nomeProfessor, string cpf, string especialidade) : nomeProfessor(nomeProfessor), cpf(cpf), especialidade(especialidade){
    cout << "Professor'" << nomeProfessor << "'criado com sucesso!\n";}

    const string getNome() const { return nomeProfessor; }
    
    ~Professor(){ cout << "Professor'" << nomeProfessor << "'removido com sucesso!\n";}


};
class Aluno
{
  private:
    string nomeAluno, ra; 
  public:
    Aluno(string nomeAluno, string ra) : nomeAluno(nomeAluno), ra(ra){
      cout << "Aluno'" << nomeAluno << "'criado com sucesso\n";
    }
    ~Aluno(){ cout << "Aluno'" << nomeAluno << "'removido com sucesso!\n";}
    
    const string getNome() const { return nomeAluno; }
};
class Turma
{
  private:
    string cod_turma;
    Professor* professor;
    vector<shared_ptr<Aluno>> alunos;
  public:
    Turma(string cod_turma, Professor* professor) : cod_turma(cod_turma), professor(professor){
      cout << "Turma:'" << cod_turma << "'criada com sucesso\n";}
    
    void adicionarAluno(shared_ptr<Aluno> aluno){
      alunos.push_back(aluno);
    }

    void listarTurma() const{
      cout << "\n----------------------";
      cout << "\n-----Imprime Turma----"; 
      cout << "\n----------------------";
      cout << "\nCod turma: '" << cod_turma;
      cout << "\nProfessor: '" << professor->getNome() << "'"; 
      for(const auto& a  : alunos){
        cout << "\nAluno: '" << a->getNome() << "'";
      }
      cout << "\n----------------------\n";
    }
    ~Turma(){ 
      cout << "Turma:'" << cod_turma << "'deletada!\n";}
  
};


int main()
{
    Professor* prof = new Professor("Carlos", "123.456.789-00", "Matemática");

    Turma turma("3A", prof);

    turma.adicionarAluno(make_shared<Aluno>("João", "RA123"));
    turma.adicionarAluno(make_shared<Aluno>("Clara", "RA456"));
    turma.adicionarAluno(make_shared<Aluno>("Marcos", "RA789"));

    turma.listarTurma();

    delete prof;
  return 5;
}


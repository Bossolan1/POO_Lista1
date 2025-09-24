#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Motorista
{
  private:
    string nomeMotorista, cpf;
  public:
    Motorista(string nomeMotorista, string cpf) : nomeMotorista(nomeMotorista), cpf(cpf){
      cout << "Motorista '" << nomeMotorista << "' criado com sucesso!\n";
    }
    const string getNome() const { return nomeMotorista; }
    ~Motorista(){ cout << "Motorista '" << nomeMotorista << "' removido com sucesso!\n"; }
};

class Parada
{
  private:
    string nomeParada, endereco;
  public:
    Parada(string nomeParada, string endereco) : nomeParada(nomeParada), endereco(endereco){
      cout << "Parada '" << nomeParada << "' criada com sucesso!\n";
    }
    const string getNome() const { return nomeParada; }
    ~Parada(){ cout << "Parada '" << nomeParada << "' removida com sucesso!\n"; }
};

class Rota
{
  private:
    string codigoRota;
    vector<shared_ptr<Parada>> paradas;
  public:
    Rota(string codigoRota) : codigoRota(codigoRota){
      cout << "Rota '" << codigoRota << "' criada com sucesso!\n";
    }

    void adicionarParada(shared_ptr<Parada> parada){
      paradas.push_back(parada);
    }

    void listarParadas() const{
      cout << "Paradas da rota '" << codigoRota << "':\n";
      for(const auto& p : paradas){
        cout << "- " << p->getNome() << "\n";
      }
    }

    ~Rota(){ cout << "Rota '" << codigoRota << "' deletada!\n"; }
};

class Onibus
{
  private:
    string codigoOnibus;
    Motorista* motorista;
    shared_ptr<Rota> rota;
  public:
    Onibus(string codigoOnibus, Motorista* motorista, shared_ptr<Rota> rota)
      : codigoOnibus(codigoOnibus), motorista(motorista), rota(rota){
      cout << "Ônibus '" << codigoOnibus << "' criado com sucesso!\n";
    }

    void listarInfo() const {
      cout << "\nÔnibus: " << codigoOnibus << "\nMotorista: " << motorista->getNome() << "\n";
      rota->listarParadas();
    }

    ~Onibus(){ cout << "Ônibus '" << codigoOnibus << "' deletado!\n"; }
};

class Frota
{
  private:
    vector<shared_ptr<Onibus>> onibus;
  public:
    void adicionarOnibus(shared_ptr<Onibus> o){
      onibus.push_back(o);
    }

    void listarFrota() const {
      cout << "\n--- Frota da empresa ---\n";
      for(const auto& o : onibus){
        o->listarInfo();
      }
      cout << "------------------------\n";
    }
};

int main()
{
  Motorista* m1 = new Motorista("José", "111.222.333-44");
  Motorista* m2 = new Motorista("Maria", "555.666.777-88");

  auto rota1 = make_shared<Rota>("R1");
  rota1->adicionarParada(make_shared<Parada>("Parada A", "Rua 1"));
  rota1->adicionarParada(make_shared<Parada>("Parada B", "Rua 2"));

  auto rota2 = make_shared<Rota>("R2");
  rota2->adicionarParada(make_shared<Parada>("Parada C", "Rua 3"));
  rota2->adicionarParada(make_shared<Parada>("Parada D", "Rua 4"));

  auto onibus1 = make_shared<Onibus>("Ônibus 101", m1, rota1);
  auto onibus2 = make_shared<Onibus>("Ônibus 102", m2, rota2);

  Frota frota;
  frota.adicionarOnibus(onibus1);
  frota.adicionarOnibus(onibus2);

  frota.listarFrota();

  delete m1;
  delete m2;

  return 6;  
}


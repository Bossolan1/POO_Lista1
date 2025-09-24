#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Autor
{
    private:
        string nome, cpf;
    public:
        Autor(string nome, string cpf) : nome(nome),cpf(cpf) { cout << "autor: '" << nome << "' criado\n"; }
        
        ~Autor(){ cout << "Autor:'" << nome << "' destruido\n"; }
        
        const string getNome() const { return nome; }
}; 

class Musica 
{
    private:
        string titulo, genero ,anoDePublicacao;
        Autor* autor;
    public:
        Musica(string titulo, string genero,Autor* autor, string anoDePublicacao) : titulo(titulo), genero(genero) ,autor(autor), anoDePublicacao(anoDePublicacao){
            cout << "Musica('" << titulo << "') criado\n";
        }
        ~Musica() { cout << "Musica('" << titulo << "') destruida\n"; } 
        
        void listarMusica() const
        {
            cout << "\nTitulo: " << titulo;
            cout << "\nGenero: " << genero;
            cout << "\nAutor: " << autor->getNome();
            cout << "\nAno de publicacao: " << anoDePublicacao;
            cout << "\n";
        }

        const string& getTitulo() const { return titulo; }
};

class Playlist {
private:    
    string nome;
    vector<Musica*> musicas_cadastradas; // COMPOSIÇÃO
public:
    Playlist(const string& n) : nome(n) {cout << "Biblioteca('" << nome << "') criada\n"; }
    ~Playlist() { cout << "Biblioteca('" << nome << "') destruida\n"; }

    void adicionarMusica(Musica* musica) { musicas_cadastradas.push_back(musica); }
    
    void exibirMusicas() const
    {
        cout << "\n-----------------------------";
        cout << "\n| Exibidor de musicas makrI |";
        cout << "\n-----------------------------";
        for (const  auto& musica: musicas_cadastradas)
        {
            musica->listarMusica();
        }
        cout << "\n----------------------------\n";
    }
};


int main() {
    {
        Autor autor1("Sewerslvt", "123.456.789-00");
        Autor autor2("Skrilet", "987.654.321-00");
        Autor autor3("Music sheet style", "111.222.333-44");
        
        Musica livro1("Mr Kill myserlf","breakcore", &autor1, "22-01-2018");
        Musica livro2("Monster","heavymetal",&autor2, "22-01-2013");
        Musica livro3("Rush E","indie",&autor3, "22-01-2015");

        Playlist  playlist("Biblioteca California");

        playlist.adicionarMusica(&livro1);
        playlist.adicionarMusica(&livro2);
        playlist.adicionarMusica(&livro3);


        playlist.exibirMusicas();
    }

    return 2;
}

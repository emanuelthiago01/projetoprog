#include "empresa.h"
#include <algorithm>
#include <QDebug>
#include <QFile>


bool Empresa::TestarFuncionario(Funcionario a)
{
    if( InvalidarNumero(a.getNome()) && testeNome(a.getNome()) && testeDiasf(a.getDiasf()) && testeHorasd(a.getHorasd()) && testeSalario(a.getSalario()) && testeVendast(a.getVendast()) && testeComissao(a.getComissao()) && testeId(a.getId()) && testarId(a.getId()) ){
     return 1;
    }
    else{
        return 0;

    }
}

void Empresa::OrganizarPorNome()
{
    std::sort(funcionarios.begin(),funcionarios.end(),organizarPorNome);

}

void Empresa::OrganizarPorSalario()
{
    std::sort(funcionarios.begin(),funcionarios.end(),organizarPorSalario);
}

void Empresa::EditarFuncionario(Funcionario a,int tam)
{
   funcionarios[tam] = a;
}

int Empresa::PosicaoDoFuncionario(Funcionario a)
{
    int i;
    for(i = 0;a.getId()!=funcionarios[i].getId();i++){

    }
    return i;
}


void Empresa::OrganizarPorProdutividade()
{
    std::sort(funcionarios.begin(),funcionarios.end(),organizarPorProdutividade);
}

void Empresa::OrganizarPorId()
{
    std::sort(funcionarios.begin(),funcionarios.end(),organizarPorId);
}


void Empresa::InserirFuncionario(Funcionario a)
{
   funcionarios.push_back(a);
   //qDebug() << a.getId();

}

Empresa::Empresa()
{

}
bool Empresa::salvarFuncionario(QString arquivo)
{
    QFile file(arquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly))
        return false;

    for(Funcionario a : funcionarios){
        a.CalcSalandProd();
        linha = a.getNome() + ',' + a.getId() + ',' + QString::number(a.getSalariot()) + ',' + QString::number(a.getProdutividade()) + ',' + QString::number(a.getDiasf()) + ',' + QString::number(a.getHorasd()) + ',' + QString::number(a.getSalario()) + ',' + QString::number(a.getVendast()) + ',' + QString::number(a.getComissao()) + '\n' ;
        file.write(linha.toLocal8Bit());
    }
    return true;

}
bool Empresa::carregarFuncionario(QString arquivo)
{
    QFile file(arquivo);
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QString linha;
    Funcionario a;
    while(!file.atEnd()){
        linha = file.readLine();
        QStringList dados = linha.split(",");
        a.setNome(dados[0]);
        a.setId(dados[1]);
        a.setSalariot(dados[2].toFloat());
        a.setProdutividade(dados[3].toFloat());
        a.setDiasf((dados[4].toFloat()));
        a.setHorasd(dados[5].toFloat());
        a.setSalario(dados[6].toFloat());
        a.setVendast(dados[7].toFloat());
        a.setComissao(dados[8].toFloat());
        if(TestarFuncionario(a)){
        InserirFuncionario(a);

        }

    }
    return true;
}

int Empresa::size()
{
    return funcionarios.size();
}


float Empresa::msalario()
{
    float media = 0;
    for(int i = 0;i<funcionarios.size();i++){
        media = funcionarios[i].getSalariot() + media;
    }
    if(funcionarios.size() != 0){
    media = media / funcionarios.size();
    }
    else{
        media = 0;
    }
    return media;
}

float Empresa::mprod()
{
    float media = 0;
    for(int i = 0;i<funcionarios.size();i++){
        media = funcionarios[i].getProdutividade() + media;
    }
    if(funcionarios.size() != 0){
    media = media / funcionarios.size();
    }
    else{
        media = 0;
    }
    return media;
}

Funcionario Empresa::ProcurarFuncionario(Funcionario a)
{
    QString b = a.getId();
    int i;
    for(i = 0;b!=funcionarios[i].getId();i++){

    }
    return funcionarios[i];
}


bool Empresa::TestarFuncionarioEspecial(Funcionario a)
{
    if(InvalidarNumero(a.getNome()) && testeNome(a.getNome()) && testeDiasf(a.getDiasf()) && testeHorasd(a.getHorasd()) && testeSalario(a.getSalario()) && testeVendast(a.getVendast()) && testeComissao(a.getComissao()) && testarId(a.getId()) ){
     return 1;
    }
    else{
        return 0;

    }
}

bool Empresa::TestarId2(Funcionario a)
{
    for(int i = 0;i<funcionarios.size();i++){
        if(a.getId()==funcionarios[i].getId()){
            return 1;
        }
    }
    return 0;
}

void Empresa::eraser()
{
    funcionarios.erase(funcionarios.begin(),funcionarios.end());
}

void Empresa::eraserespecifico(Funcionario a)
{
 int j = PosicaoDoFuncionario(a);
 funcionarios.erase(funcionarios.begin() + j);

}


Funcionario Empresa::operator [](int i)
{
    return funcionarios[i];
}


bool organizarPorNome(Funcionario a,Funcionario b){
    return a.getNome().toLower()<b.getNome().toLower();
}
bool organizarPorSalario(Funcionario a, Funcionario b){
    return a.getSalariot()>b.getSalariot();
}
bool organizarPorProdutividade(Funcionario a, Funcionario b){
    return a.getProdutividade()>b.getProdutividade();
}


bool organizarPorId(Funcionario a, Funcionario b)
{
    return a.getId().toInt()<b.getId().toInt();
}
bool testeNome(QString name){
    if(name.size()<3){
        return 0;
    }
    else{
        return 1;
    }
}

bool testeComissao(float value)
{
    if(value <0 || value > 100 ){
        return 0;
    }
    else{
        return 1;
    }
}

bool testeSalario(float value)
{
    if(value <= 0){
        return 0;
    }
    else{
        return 1;
    }
}

bool testeDiasf(float value)
{
    if(value < 0 || value > 30){
        return 0;
    }
    else{
        return 1;
    }
}

bool testeHorasd(float value)
{
    if(value <= 0 || value > 24){
        return 0;
    }
    else{
        return 1;
    }
}

bool testeVendast(float value)
{
    if(value < 0){
        return 0;
    }
    else{
        return 1;
    }
}


bool Empresa::testeId(QString id)
{
    for(int i = 0;i<funcionarios.size();i++){
        if(id == funcionarios[i].getId()){
            qDebug() << "flag";
            return 0;
        }
    }
    return 1;
}

bool testarId(QString value)
{
    if(value.toInt() <= 0){
        return 0;
    }
    return 1;
}

bool InvalidarNumero(QString a)
{
    QString numeros = "0123456789";
    for(int j = 0;j<a.size();j++){
        for(int k = 0;k<numeros.size();k++){
            if(a[j] == numeros[k]){
                return 0;
            }
        }
    }
    return 1;
}

bool InvalidarChar(float a)
{
   bool testar = 1;
   bool testar_2 = 0;
    QString teste = QString::number(a);
    QString numeros = "0123456789.";
    for(int j = 0;j<teste.size();j++){
        testar_2 = 0;
        for(int k = 0;k<numeros.size();k++){
            if(teste[j] == numeros[k]){
               testar_2 = 1;
            }
            else {
            }
        }
        testar = testar && testar_2;
    }
    return testar;
}



bool InvalidarTudo(Funcionario a)
{
 bool testarSalario = InvalidarChar(a.getSalario());
 bool testarSalariot = InvalidarChar(a.getSalariot());
 bool testarComissao = InvalidarChar(a.getComissao());
 bool testarVendast = InvalidarChar(a.getVendast());
 bool testarProdutividade = InvalidarChar(a.getProdutividade());
 bool testarHorasd = InvalidarChar(a.getHorasd());
 bool testarDiasf = InvalidarChar(a.getDiasf());
 bool testarNome = InvalidarNumero(a.getNome());
 if(testarSalario && testarComissao && testarNome && testarVendast && testarHorasd && testarDiasf && testarSalariot && testarProdutividade){
     return 1;

}
 else{
     return 0;
 }

}

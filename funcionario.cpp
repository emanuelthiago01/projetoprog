#include "funcionario.h"

QString Funcionario::getNome() const
{

    return nome;
}

void Funcionario::setNome(const QString &value)
{
    nome = value; 
}

float Funcionario::getProdutividade()
{
    return produtividade;
}

float Funcionario::getComissao() const
{
    return comissao;
}

void Funcionario::setComissao(float value)
{
        comissao = value;
}

float Funcionario::getHorasd() const
{
    return horasd;
}

void Funcionario::setHorasd(float value)
{
            horasd = value;
}

float Funcionario::getDiasf() const
{
    return diasf;
}

void Funcionario::setDiasf(float value)
{
            diasf = value;
}

float Funcionario::getSalario() const
{
    return salario;
}

void Funcionario::setSalario(float value)
{
  salario = value;

}

float Funcionario::getVendast() const
{

    return vendast;
}

void Funcionario::setVendast(float value)
{
            vendast = value;

}


float Funcionario::getSalariot()
{
    return salariot;
}

void Funcionario::setSalariot(float value)
{
    salariot = value;
}

void Funcionario::setProdutividade(float value)
{
    produtividade = value;
}

QString Funcionario::getId() const
{
    return id;
}

void Funcionario::setId(const QString &value)
{
    id = value;
}


void Funcionario::operator =(Funcionario a)
{

    id = a.getId();
    nome = a.getNome();
    comissao = a.getComissao();
    horasd = a.getHorasd();
    diasf = a.getDiasf();
    salario = a.getSalario();
    vendast = a.getVendast();
    salariot = a.getSalariot();
    produtividade = a.getProdutividade();
}

void Funcionario::CalcSalandProd()
{
    setSalariot(horasd*(30-diasf)*salario + getVendast()*getComissao()/100);
    setProdutividade(vendast/(horasd*30));

}

Funcionario::Funcionario()
{
    nome = "as";
    salario = 1;
    horasd = 1;
    diasf = 0;
    id = "as";
    vendast = 0;
    comissao = 0;


    
}
float valorTotal(float value, float value2){
    float vreal;
    vreal = value*value2;
    return vreal;
}

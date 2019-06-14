#ifndef EMPRESA_H
#define EMPRESA_H

#include <QObject>
#include <QVector>
#include "funcionario.h"
#include <algorithm>

class Empresa
{
private:
    QVector<Funcionario> funcionarios;
public:
    void MontarId();
    bool TestarFuncionario(Funcionario a);
    void OrganizarPorNome();
    void OrganizarPorSalario();
    void EditarFuncionario(Funcionario a, int tam);
    int PosicaoDoFuncionario(Funcionario a);
    void OrganizarPorProdutividade();
    void OrganizarPorId();
    void InserirFuncionario(Funcionario a);
    Empresa();
    void InserirFuncionarioNaTabela(int linha, Funcionario funcionario, int organizar);
    Funcionario operator [](int i);
    bool salvarFuncionario(QString arquivo);
    bool carregarFuncionario(QString arquivo);
    bool testeId(QString id);
    int size();
    float msalario();
    float mprod();
    Funcionario ProcurarFuncionario(Funcionario a);
    bool TestarFuncionarioEspecial(Funcionario a);
    bool TestarId2(Funcionario a);
    void eraser();
    void eraserespecifico(Funcionario a);
};
bool organizarPorNome(Funcionario a,Funcionario b);
bool organizarPorSalario(Funcionario a, Funcionario b);
bool organizarPorProdutividade(Funcionario a,Funcionario b);
bool organizarPorId(Funcionario a,Funcionario b);
bool testeNome(QString name);
bool testeHorasd(float value);
bool testeDiasf(float value);
bool testeSalario(float value);
bool testeComissao(float value);
bool testeVendast(float value);
bool testarId(QString value);
bool InvalidarNumero(QString a);
bool InvalidarChar(float a);
bool InvalidarTudo(Funcionario a);

#endif // EMPRESA_H

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <QObject>

class Funcionario
{
private:
    QString id;
    QString nome;
    float comissao;
    float horasd;
    float diasf;
    float salario;
    float vendast;
    float salariot;
    float produtividade;




public:
    void CalcSalandProd();
    Funcionario();
    QString getNome() const;
    void setNome(const QString &value);
    float getProdutividade();
    float getComissao() const;
    void setComissao(float value);
    float getHorasd() const;
    void setHorasd(float value);
    float getDiasf() const;
    void setDiasf(float value);
    float getSalario() const;
    void setSalario(float value);
    float getVendast() const;
    void setVendast(float value);
    float valorTotal(float value, float value2);
    float getSalariot();
    void setSalariot(float value);
    void setProdutividade(float value);
    QString getId() const;
    void setId(const QString &value);
    void operator =(Funcionario a);
};


#endif // FUNCIONARIO_H

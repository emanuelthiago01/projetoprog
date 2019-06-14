#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTableWidget>
#include <vector>
#include <algorithm>
#include <QFile>
#include <QObject>
#include <QDoubleValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    i = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_bfuncionario_clicked()
{

    funcionario.setNome(ui->lnome->text());
    funcionario.setId(ui->lineID->text());
    funcionario.setSalario(ui->lsalario->text().toFloat());
    funcionario.setComissao(ui->lcomissao->text().toFloat());
    funcionario.setDiasf(ui->ldiasf->text().toFloat());
    funcionario.setVendast(ui->ltvendas->text().toFloat());
    funcionario.setHorasd(ui->horasd->text().toFloat());


    funcionario.CalcSalandProd();
    QMessageBox msg;
    if(funcionarios.TestarFuncionario(funcionario)&& !(ui->lnome->text().isEmpty()) && !(ui->lineID->text().isEmpty()) && !(ui->lsalario->text().isEmpty()) && !(ui->lcomissao->text().isEmpty()) && !(ui->ldiasf->text().isEmpty()) && !(ui->ltvendas->text().isEmpty()) && !(ui->horasd->text().isEmpty())){
        funcionarios.InserirFuncionario(funcionario);
        i++;
        ui->label_17->setText("funcionario cadastrado !");
        ui->tableWidget->insertRow(i-1);
        ui->lnome->clear();
        ui->lineID->clear();
        ui->lsalario->clear();
        ui->lcomissao->clear();
        ui->ldiasf->clear();
        ui->ltvendas->clear();
        ui->horasd->clear();


    }
    else{
      ui->label_17->setText("um ou mais dados invalidos");
        msg.setText("dados invalidos");
        msg.exec();

    }
    inserirNaTabela();





}
void MainWindow::inserirNaTabela(){



    for (int j = 0;j<funcionarios.size();j++){



     ui->tableWidget->setItem(j,0,new QTableWidgetItem(funcionarios[j].getNome()));

     ui->tableWidget->setItem(j,1,new QTableWidgetItem(funcionarios[j].getId()));

     ui->tableWidget->setItem(j,2,new QTableWidgetItem(QString::number(funcionarios[j].getSalariot())));

     ui->tableWidget->setItem(j,3,new QTableWidgetItem(QString::number(funcionarios[j].getProdutividade())));
 }
    EstatisticasDaTabela();
}

void MainWindow::EstatisticasDaTabela()
{
 ui->labelf->setText(QString::number(funcionarios.size()));
 ui->labels->setText(QString::number(funcionarios.msalario()));
 ui->labelp->setText(QString::number(funcionarios.mprod()));
}

void MainWindow::on_pushButton_clicked()
{

  inserirNaTabela();
}

void MainWindow::on_pushButton_4_clicked()
{
    funcionarios.OrganizarPorSalario();
    inserirNaTabela();
}

void MainWindow::on_pushButton_5_clicked()
{
    funcionarios.OrganizarPorNome();
    inserirNaTabela();
    //QString a = "";


}


void MainWindow::on_actionSalvar_triggered()
{
    QString nomeArquivo = QFileDialog::getSaveFileName(this,
                                                           "Lista de funcionarios",
                                                           "",
                                                           "CSV(*.csv)");
        funcionarios.salvarFuncionario(nomeArquivo);
}

void MainWindow::on_actionAbrir_triggered()
{

    QString nomeArquivo = QFileDialog::getOpenFileName(this,
                                                           "Lista de aluno",
                                                           "",
                                                           "CSV(*.csv)");

        funcionarios.carregarFuncionario(nomeArquivo);
        qDebug() << funcionarios.size();

        for(;i<funcionarios.size();){
            i++;
            qDebug() << i;
            ui->tableWidget->insertRow(i-1);
            inserirNaTabela();
        }



}

void MainWindow::on_pushButton_6_clicked()
{
    funcionarios.OrganizarPorProdutividade();
    inserirNaTabela();
}

void MainWindow::on_bfuncionario_2_clicked()
{
    funcionariot.setId(ui->lid->text());
    if(funcionarios.TestarId2(funcionariot)){
    funcionariot = funcionarios.ProcurarFuncionario(funcionariot);
    qDebug() << funcionariot.getSalario();
    ui->lsalario_2->setText(QString::number(funcionariot.getSalario()));
    ui->ltvendas_2->setText(QString::number(funcionariot.getVendast()));
    ui->lcomissao_2->setText(QString::number(funcionariot.getComissao()));
    ui->lineEdit->setText(funcionariot.getNome());
    ui->ldiasf_2->setText(QString::number(funcionariot.getDiasf()));
    ui->horasd_2->setText(QString::number(funcionariot.getHorasd()));
}
    else{
        ui->label_18->setText("ID não cadastrado");
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    funcionarios.OrganizarPorId();
    inserirNaTabela();

}

void MainWindow::on_pushButton_7_clicked()
{
    funcionario.setId(ui->lid->text());
    funcionario.setNome(ui->lineEdit->text());
    funcionario.setSalario(ui->lsalario_2->text().toFloat());
    funcionario.setComissao(ui->lcomissao_2->text().toFloat());
    funcionario.setDiasf(ui->ldiasf_2->text().toFloat());
    funcionario.setVendast(ui->ltvendas_2->text().toFloat());
    funcionario.setHorasd(ui->horasd_2->text().toFloat());
    funcionario.CalcSalandProd();
    if(funcionarios.TestarFuncionarioEspecial(funcionario) && funcionarios.TestarId2(funcionario)){
        funcionarios.EditarFuncionario(funcionario, funcionarios.PosicaoDoFuncionario(funcionario));
        ui->label_18->setText("funcionario Editado !");
        ui->lineEdit->clear();
        ui->lineEdit->clear();
        ui->lsalario_2->clear();
        ui->lcomissao_2->clear();
        ui->ldiasf_2->clear();
        ui->ltvendas_2->clear();
        ui->horasd_2->clear();



    }
    else{
        ui->label_18->setText("Um ou mais dados inválidos");

    }
    inserirNaTabela();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label_19->setText("Pronto para receber dados");
    ui->label_21->setText(" ");
    QDoubleValidator* validator = new QDoubleValidator(this);
    ui->ltvendas->setValidator(validator);
    ui->lineID->setValidator(validator);
    ui->lsalario->setValidator(validator);
    ui->lcomissao->setValidator(validator);
    ui->ldiasf->setValidator(validator);
    ui->horasd->setValidator(validator);
    ui->ltvendas_2->setValidator(validator);
    ui->lid->setValidator(validator);
    ui->lsalario_2->setValidator(validator);
    ui->lcomissao_2->setValidator(validator);
    ui->ldiasf_2->setValidator(validator);
    ui->horasd_2->setValidator(validator);
}

void MainWindow::on_pushButton_3_clicked()
{
    int k = funcionarios.size();
    for(int j = 0;j<funcionarios.size();j++){

        ui->tableWidget->removeRow(k);
        k = k - 1;
        i--;
    }
    ui->tableWidget->removeRow(0);
    funcionarios.eraser();
    inserirNaTabela();

    qDebug() << funcionarios.size();
}

void MainWindow::on_pushButton_9_clicked()
{
    Funcionario a;
    a.setId(ui->lid->text());
    if(funcionarios.TestarId2(a)){
    int t = funcionarios.PosicaoDoFuncionario(a);
    funcionarios.eraserespecifico(a);
    i--;
    ui->tableWidget->removeRow(t);
    inserirNaTabela();
    ui->label_18->setText("funcionario Removido !");

    }
    ui->lineEdit->clear();
    ui->lineEdit->clear();
    ui->lsalario_2->clear();
    ui->lcomissao_2->clear();
    ui->ldiasf_2->clear();
    ui->ltvendas_2->clear();
    ui->horasd_2->clear();
}

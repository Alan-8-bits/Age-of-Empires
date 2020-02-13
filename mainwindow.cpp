#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iomanip>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_guardar_nom_clicked()
{
    menu.setNombre_usuario(ui->nombre_usuario->text().toStdString());
}

void MainWindow::on_primera_civ_clicked()
{
    if(menu.total()==0){
        ui->pantalla->clear();
        ui->pantalla->insertPlainText("No se ha creado ninguna civilizacion");
    }
    else {
    ui->pantalla->clear();
    ui->pantalla->insertPlainText("\tPrimera Civilizacion\n"
                                  "Nombre: " +QString::fromStdString(menu.primera_civilizacion().getNombre())+"\n"
                                  "Ubicacion en X: " +QString::number(menu.primera_civilizacion().getUbicacion_x())+"\n"
                                  "Ubicacion en Y: "+QString::number(menu.primera_civilizacion().getUbicacion_y())+"\n");
    }
}

void MainWindow::on_ultima_civ_clicked()
{
    if(menu.total()==0){
        ui->pantalla->clear();
        ui->pantalla->insertPlainText("No se ha creado ninguna civilizacion");
    }
    else {
        ui->pantalla->clear();
        ui->pantalla->insertPlainText("\tUltima Civilizacion\n"
                                      "Nombre: " +QString::fromStdString(menu.ultimo_civilizacion().getNombre())+"\n"
                                      "Ubicacion en X: " +QString::number(menu.ultimo_civilizacion().getUbicacion_x())+"\n"
                                      "Ubicacion en Y: "+QString::number(menu.ultimo_civilizacion().getUbicacion_y())+"\n");
    }
}

void MainWindow::on_ordenar_clicked()
{
    if(menu.total()==0){
        ui->pantalla->clear();
        ui->pantalla->insertPlainText("No se ha creado ninguna civilizacion");
    }
    else {
    ui->pantalla->clear();
    menu.ordenar();
    ui->pantalla->insertPlainText("Se ordenaron las civilizaciones");
    }
}

void MainWindow::on_resumen_clicked()
{
    ui->pantalla->clear();

    ui->pantalla->insertPlainText("Nombre de Usuario: "+QString::fromStdString(menu.getNombre_usuario())+"\n"
                                  "Numero de Civilizaciones: "+QString::number(menu.total())+"\n\n"
                                  "  Nombre\tUbi. X\tUbi. Y\n\n");
    for (int i = 0; i < menu.total(); i++) {

        ui->pantalla->insertPlainText(QString::fromStdString(menu[i].getNombre()) +
                                  "\t" +QString::number(menu[i].getUbicacion_x())+
                                  "\t" +QString::number(menu[i].getUbicacion_y())+"\n");
    }
}

void MainWindow::on_agregar_clicked()
{
    if(ui->pos_agr->value()>menu.total()){
        QMessageBox::information(this,"Error",
                                 "Posicion no valida");
    }
    else{
    Civilizacion a;
    a.setNombre(ui->nombre_civ_agr->text().toStdString());
    a.setUbicacion_x(ui->pos_x_agr->value());
    a.setUbicacion_y(ui->pos_y_agr->value());

    menu.agregar_civilizacion(a,ui->pos_agr->value());
    }
}

void MainWindow::on_inicializar_clicked()
{
    Civilizacion a;
    a.setNombre(ui->nombre_civ_ini->text().toStdString());
    a.setUbicacion_x(ui->pos_x_ini->value());
    a.setUbicacion_y(ui->pos_y_ini->value());

    menu.crear_civilizaciones(ui->numero_civ_ini->value(),a);
}

void MainWindow::on_eliminar_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        menu.eliminar_civilizacion(ui->nombre_eliminar->text().toStdString());
    }
}

void MainWindow::on_Buscar_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        if(menu.existe_civ(ui->nombre_buscar->text().toStdString())){

            ui->pantalla2->clear();
            ui->pantalla2->insertPlainText("Que deseas hacer con esta civilizacion?.");
        }
        else {
            QMessageBox::information(this,"Error",
                                     "No existe esa civilizacion");
        }
    }
}

void MainWindow::on_agr_ini_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        if(menu.existe_civ(ui->nombre_buscar->text().toStdString())){
            Aldeano a;
            a.setNombre(ui->nom_ald_agr->text().toStdString());
            a.setSalud(ui->salud_ald_agr->value());
            a.setEdad(ui->edad_ald_agr->value());
            a.setGenero(ui->genero_ald_agr->text().toStdString());

            string nombre=ui->nombre_buscar->text().toStdString();
            menu.buscar_civilizaciones(nombre)->agregarInicio(a);

            size_t x=menu.buscar_civilizaciones(nombre)->numeroAldeanos();

            ui->pantalla2->clear();
            ui->pantalla2->insertPlainText("Se ha agregado a "+ui->nom_ald_agr->text()+" al inicio\n"+
                                           "Ahora hay "+QString::number(x)+" aldeanos");
        }
        else {
            QMessageBox::information(this,"Error",
                                     "No existe esa civilizacion");
        }
    }
}

void MainWindow::on_agr_fin_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        if(menu.existe_civ(ui->nombre_buscar->text().toStdString())){
            Aldeano a;
            a.setNombre(ui->nom_ald_agr->text().toStdString());
            a.setSalud(ui->salud_ald_agr->value());
            a.setEdad(ui->edad_ald_agr->value());
            a.setGenero(ui->genero_ald_agr->text().toStdString());

            menu.buscar_civilizaciones(ui->nombre_buscar->text().toStdString())->agregarFinal(a);
            size_t x=menu.buscar_civilizaciones(ui->nombre_buscar->text().toStdString())->numeroAldeanos();

            ui->pantalla2->clear();
            ui->pantalla2->insertPlainText("Se ha agregado a "+ui->nom_ald_agr->text()+" al final\n"+
                                           "Ahora hay "+QString::number(x)+" aldeanos");
        }
        else {
            QMessageBox::information(this,"Error",
                                     "No existe esa civilizacion");
        }
    }
}

void MainWindow::on_eliminar_ald_nom_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        if(menu.existe_civ(ui->nombre_buscar->text().toStdString())){

            menu.buscar_civilizaciones(ui->nombre_buscar->text().toStdString())->eliminarNombre(ui->nombre_eli_ald->text().toStdString());

            ui->pantalla2->clear();
            ui->pantalla2->insertPlainText("Se ha eliminado a "+ui->nombre_eli_ald->text());
        }
        else {
            QMessageBox::information(this,"Error",
                                     "No existe esa civilizacion");
        }
    }
}

void MainWindow::on_eliminar_ald_sal_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        if(menu.existe_civ(ui->nombre_buscar->text().toStdString())){

            menu.buscar_civilizaciones(ui->nombre_buscar->text().toStdString())->eliminarSalud(ui->edad_elim->value());

            ui->pantalla2->clear();
            ui->pantalla2->insertPlainText("Se han eliminado a todos los aldeanos con salud menor a "+ui->edad_elim->value());
        }
        else {
            QMessageBox::information(this,"Error",
                                     "No existe esa civilizacion");
        }
    }
}

void MainWindow::on_eliminar_ald_eda_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        if(menu.existe_civ(ui->nombre_buscar->text().toStdString())){

            menu.buscar_civilizaciones(ui->nombre_buscar->text().toStdString())->eliminarEdad();

            ui->pantalla2->clear();
            ui->pantalla2->insertPlainText("Se han eliminado a todos los aldeanos con edad mayor o igual a 60");
        }
        else {
            QMessageBox::information(this,"Error",
                                     "No existe esa civilizacion");
        }
    }
}

void MainWindow::on_ord_ald_nom_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        if(menu.existe_civ(ui->nombre_buscar->text().toStdString())){

            menu.buscar_civilizaciones(ui->nombre_buscar->text().toStdString())->ordenarNombre();

            ui->pantalla2->clear();
            ui->pantalla2->insertPlainText("Se han ordenado a todos los aldeanos en base a su nombre.");
        }
        else {
            QMessageBox::information(this,"Error",
                                     "No existe esa civilizacion");
        }
    }
}

void MainWindow::on_ord_ald_eda_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        if(menu.existe_civ(ui->nombre_buscar->text().toStdString())){

            menu.buscar_civilizaciones(ui->nombre_buscar->text().toStdString())->ordenarEdad();

            ui->pantalla2->clear();
            ui->pantalla2->insertPlainText("Se han ordenado a todos los aldeanos en base a su edad.");
        }
        else {
            QMessageBox::information(this,"Error",
                                     "No existe esa civilizacion");
        }
    }
}

void MainWindow::on_ord_ald_sal_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        if(menu.existe_civ(ui->nombre_buscar->text().toStdString())){

            menu.buscar_civilizaciones(ui->nombre_buscar->text().toStdString())->ordenarSalud();

            ui->pantalla2->clear();
            ui->pantalla2->insertPlainText("Se han ordenado a todos los aldeanos en base a su salud.");
        }
        else {
            QMessageBox::information(this,"Error",
                                     "No existe esa civilizacion");
        }
    }
}

void MainWindow::on_actualizar_tabla_clicked()
{
    if(menu.total()==0){
        QMessageBox::information(this,"Error",
                                 "La lista esta vacia");
    }
    else {
        if(menu.existe_civ(ui->nombre_buscar->text().toStdString())){

            const size_t x=menu.numero_civ(ui->nombre_buscar->text().toStdString());
            const size_t num=menu[x].numeroAldeanos();

            ui->pantalla2->clear();
            ui->pantalla2->insertPlainText("        \t    Aldeanos de: "+ui->nombre_buscar->text()+"\n\n");
            ui->pantalla2->insertPlainText("  Nombre\tEdad\tGenero\tSalud\n\n");

            for (size_t i = 0; i < num; i++) {

                ui->pantalla2->insertPlainText(QString::fromStdString(menu[x][i]->getNombre()) +
                                               "\t" +QString::number(menu[x][i]->getEdad())+
                                               "\t" +QString::fromStdString(menu[x][i]->getGenero())+
                                               "\t" +QString::number(menu[x][i]->getSalud())+"\n");
            }
        }
        else {
            QMessageBox::information(this,"Error",
                                     "No existe esa civilizacion");
        }
    }
}

#include "statistic_set_data.h"
#include "database.h"

statistic_set_data::statistic_set_data(){

}

void statistic_set_data::set_the_data(int level){

    DataBase db;
    QString bestID = db.select("SELECT * FROM statistic_db WHERE correct = "
                   "(SELECT MAX(correct) FROM statistic_db WHERE difficult = " + QString::number(level) + ")"
                   "AND t_time = (SELECT MIN(t_time) FROM statistic_db "
                   "WHERE correct = (SELECT MAX(correct) FROM statistic_db WHERE difficult = " + QString::number(level) + "))");


    if(bestID != "Error load in database. DataBase::select(QString, int)"){

        time = db.select("SELECT t_time FROM statistic_db WHERE id = " + bestID + ";").remove(8, 4);
        correct = "Correct: " + db.select("SELECT correct FROM statistic_db WHERE id = " + bestID + ";");
        wrong = "Wrong: " + db.select("SELECT wrong FROM statistic_db WHERE id = " + bestID + ";");

    } else {
        time = "No result";
        correct = "No result";
        wrong = "No result";
    }

    // Give a name to the level
    check_the_level(level);
}

void statistic_set_data::check_the_level(int level){

    if(level == 13){
        difficult = "Easy: ";
        colour = QColor(0,204,0);
    }
    else if(level == 26){
        difficult = "Medium: ";
        colour = QColor(204,204,0);
    }
    else if(level == 39){
        difficult = "Hard: ";
        colour = QColor(255,128,0);
    }
    else if(level == 52){
        difficult = "Hardcore: ";
        colour = QColor(204,0,0);
    }
    else
        difficult = "Error statistic::hall_of_glory()";
}

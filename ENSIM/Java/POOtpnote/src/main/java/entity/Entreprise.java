package entity;

import java.util.ArrayList;
import java.util.List;

public class Entreprise extends Emprunteur {

    private List<Agence> agences;
    private List<Employe> employes;
    private String nomEntreprise;

    public Entreprise(String nomEntreprise)
    {
        this.nomEntreprise = nomEntreprise;

        agences = new ArrayList<Agence>();
        employes = new ArrayList<Employe>();
    }

    public List<Employe> listeEmployes() {
        return employes;
    }

    public List<Agence> getAgences()
    {
        return agences;
    }

    //Le stock d'une entreprise est composé du stock de l'entreprise, du stock de chaque agence ainsi que de chaque employé de l'entreprise
    @Override
    public List<Empruntable> listeMateriel()
    {
        List<Empruntable> stock = super.listeMateriel();

        for(Employe employe : employes)
        {
            stock.addAll(employe.listeMateriel());
        }

        for(Agence agence : agences)
        {
            stock.addAll(agence.listeMateriel());
        }

        return stock;
    }
}

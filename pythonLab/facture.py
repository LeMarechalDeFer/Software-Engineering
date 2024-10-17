from reportlab.lib.pagesizes import A4
from reportlab.pdfgen import canvas
from reportlab.lib.units import cm

def generate_invoice(data):
    # Crée un fichier PDF
    c = canvas.Canvas(f"facture_{data['numero_facture']}.pdf", pagesize=A4)
    width, height = A4
    
    # Entête
    c.setFont("Helvetica-Bold", 12)
    c.drawString(2*cm, height - 2*cm, f"Facture : {data['numero_facture']}")
    c.drawString(2*cm, height - 3*cm, f"Date d'émission : {data['date_emission']}")
    c.drawString(2*cm, height - 4*cm, f"Date de prestation : {data['date_prestation']}")
    
    # Infos fournisseur (vous)
    c.drawString(2*cm, height - 6*cm, f"Nom du fournisseur : {data['fournisseur_nom']}")
    c.drawString(2*cm, height - 7*cm, f"SIREN : {data['siren']}")
    c.drawString(2*cm, height - 8*cm, f"Adresse du fournisseur : {data['adresse_fournisseur']}")

    # Infos client
    c.drawString(2*cm, height - 10*cm, f"Nom du client : {data['client_nom']}")
    c.drawString(2*cm, height - 11*cm, f"Adresse du client : {data['adresse_client']}")

    # Désignation des prestations
    c.drawString(2*cm, height - 13*cm, f"Désignation : {data['designation']}")
    c.drawString(2*cm, height - 14*cm, f"Quantité : {data['quantite']} - Prix unitaire HT : {data['prix_unitaire']} €")
    c.drawString(2*cm, height - 15*cm, f"Taux de TVA : {data['tva']} %")

    # Total
    total_ht = data['quantite'] * data['prix_unitaire']
    tva = total_ht * data['tva'] / 100
    total_ttc = total_ht + tva

    c.drawString(2*cm, height - 17*cm, f"Total HT : {total_ht:.2f} €")
    c.drawString(2*cm, height - 18*cm, f"Montant TVA : {tva:.2f} €")
    c.drawString(2*cm, height - 19*cm, f"Total TTC : {total_ttc:.2f} €")

    # Pénalités et escompte
    c.drawString(2*cm, height - 21*cm, "Escompte pour paiement anticipé : néant")
    c.drawString(2*cm, height - 22*cm, f"Pénalités de retard : {data['penalites_retard']} %")
    c.drawString(2*cm, height - 23*cm, f"Indemnité de recouvrement : {data['indemnite_recouvrement']} €")
    
    # Fin du PDF
    c.save()

# Données de test pour la facture
data = {
    'numero_facture': 'FAC-2024-01',
    'date_emission': '2024-10-04',
    'date_prestation': '2024-09-30',
    'fournisseur_nom': 'Romain Blanchot',
    'siren': '123 456 789',
    'adresse_fournisseur': '123 Rue de la Loi, 75000 Paris',
    'client_nom': 'Client XYZ',
    'adresse_client': '456 Avenue du Client, 75000 Paris',
    'designation': 'Prestations de services IT',
    'quantite': 2,
    'prix_unitaire': 500,
    'tva': 20,
    'penalites_retard': 10,
    'indemnite_recouvrement': 40
}

generate_invoice(data)

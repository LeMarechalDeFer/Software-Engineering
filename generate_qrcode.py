import qrcode

# Informations de la vCard
vcard_data = """BEGIN:VCARD
VERSION:3.0
N:Blanchot;Xavier
FN:Xavier Blanchot
ORG:Hotel La Louisiane
TITLE:Directeur
TEL;TYPE=CELL:123456789
EMAIL:xavier.blanchot@gmail.com
ADR:;;60 rue de Seine;Paris;Ile-de-France;75006;France
END:VCARD"""

# Créer une instance de QRCode avec correction d'erreur plus élevée pour carte de visite
qr = qrcode.QRCode(
    version=3,  # Ajuster la version pour augmenter la taille si nécessaire
    error_correction=qrcode.constants.ERROR_CORRECT_Q,  # Correction d'erreur pour carte de visite
    box_size=10,
    border=4,
)

# Ajouter les données de la vCard
qr.add_data(vcard_data)
qr.make(fit=True)

# Créer l'image du QR code
img = qr.make_image(fill="black", back_color="white")
img.save("vcard_qrcode.png")


class Vertex:
    ''' Creates a vertex '''

    def __init__(self, name, latitude, longitude, profession, availability):
        self.name = name
        self.latitude = latitude
        self.longitude = longitude
        self.profession = profession
        self.availability = availability

    def __str__(self):
        return ( 'Name: {}\nLatitude: {}\nLongitude: {}\nProfession: {}\n'
                'Availability: {}'.format(self.name, self.latitude,
                    self.longitude, self.profession, self.availability) )

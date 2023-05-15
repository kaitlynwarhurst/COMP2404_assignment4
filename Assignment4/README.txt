Name: Emily Warhurst
Student Number: 101217643

To create executable: Use the following command in the terminal (in the directory with all the files):
		make
To run executable created:
		./a4

(File descriptions are taken straight from the assignment specs)
Files:
	The Date class (Entity object): 
		Files: Date.cc, Date.h
		Store information about Dates
	The Array class (Container object):
		Files: Array.h
		An abstract container for data with overloaded operators.
	The Photo class (Entity object):
		Files: Photo.h, Photo.cc
		Contains information about a particular photo.
	The Album class (Entity object):
		Files: Album.h, Album.cc
		Contains information about the album.
		Maintains a collection of Photos.
	The Criteria class (Entity object):
		Files: Criteria.c, Criteria.h
		This class is used to match user searches to matching Photo objects. There are an additional three derived
		classes arranged in a diamond hierarchy, Cat_Criteria (category), Date_Criteria, and CandD_Criteria
		(both date and category).
	The MediaFactory class (Boundary object):
		Files: MediaFactory.h, MediaFactory.cc
		This class is used to create Photos, Albums, and Criteria objects. It separates our application logic from
		the creation of Photos, Albums, or Criteria types.
	 The PhotoGram class (Container/Control object):
		Files:PhotoGram.cc, PhotoGram.h
		This class contains the master list of Photos and a collection of Albums. Users can add Photos to the
		master list, and add or remove Albums. In addition we can search for Photos and these Photos can be
		added to an Album (we will not worry about removing Photos from an Album in this assignment). In
		addition, in conjunction with the AlbumCreator and View objects, users can browse Albums and Photos.
	The AlbumCreator class (Control object):
		Files: AlbumCreator.cc, AlbumCreator.h
		Controls the interaction of PhotoGram with the View.
		Maintains its own list of Photos found during the latest search.
	The View class (Boundary object):
		Files: View.h, View.cc
		Prints menus, Albums, or Photos, and takes input
	
# WEBM-HOSTING WEBSITE
#### Video Demo:  https://www.youtube.com/watch?v=UMPvqOz969U
#### Description:
This application allows the user to upload or watch videos in the webm format.

## General informations:

### Model:
- The app possesses a database with three tables: user, video, and comment.
- User stores an user's id, username and password. The Video table stores all the relevant details about a video that can be viewed on the website, and also the foreign keys linking a video to its uploader and the comments under it.
- This database is implemented using SQLAlchemy. Flask-Migrate is used to update it.
- There's an auxiliary function used to generate unique filenames, to avoid problems with users manipulating videos they uploaded with similar filenames.
### Controller:
- The application is made using the Flask framework.
- An unregistered user can watch videos, download them and search them or look for a specific category.
- A registered user can upload videos, leave or delete comments, and possess a viewing/uploading history.
- The 'categories' global variable is sent to all templates, since it's specific to the layout wrapping all the others. There was probably a better way to go about it, but since it was not a recurring issue (one that would concern multiple variables and parts of the templates), I did not think it was worth thinking about too much.
- The thumbnails are stored in the static folder, and the videos are . Since that webms are usually short videos and that the app is likely not going to be deployed, I saw no need for using other options like Cloud storage.
### Views:
- 'Layout.html' is the wrapper for all the other templates.
- The application uses the 'Lux' theme from Bootswatch, it requires a bootstrap bundle from the fifth version onwards and jquery for the dropdown menu and such features.
- The thumbnails are stored in the static folder, and the videos are . Since webms are usually used for short videos and that the this website is not meant for deployment, I saw no need for using options like Cloud storage.
- Templates ask for names of all sorts (filenames, usernames etc) and not ids. I thought it made for more meaningful links.

## Files:
- Instance/videos.db: the database created in app.py.
- Migrations: documents the changes the database went throught. Having lost my files after reinstalling Windows due to a WIFI problem, I had to rewrite the project recently, and so it does not contain many versions.
- Static: the bootstrap theme file, the thumbnails and the videos.
- Templates: the views.
- App.py: the routes.
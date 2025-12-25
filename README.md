<h1>Image Viewer</h1>
<p>That's an image viewer I made for studying the C programming language</p>
<p>Supported files:</p>
<ul>
  <li>PPM P3</li>
  <li>PPM P6</li>
</ul>
<h2>How to use it:</h2>
<code>git clone https://github.com/Sebastianbvm/ImageViewer.git</code> <br>
<code>cd ImageViewer</code> <br>
<code>gcc -o viewer main.c image.c ppm.c $(pkg-config --cflags --libs sdl3) && ./viewer</code>

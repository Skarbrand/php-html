<h1>php-html<h1>

<v2>Introduction<v2>



<v2>Sample<v2>
```ruby
	require_once("lib/class/class_html.inc");
	
	$page = new html_page;
	$page->html_title('php-html');
	$page->html_style('style/some_stylesheet.css');
	$page->html_label('Hello World!');
	$page->html_render();
```
